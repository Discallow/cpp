#include "PMerge.hpp"

int comparisons = 0;

template <typename Container>
PMergeMe<Container>::PMergeMe(): _firstIndex(0), _secondIndex(0), _blockSize(0), _recursiveLevels(1), _boundaryIndex(0) {

}

template <typename Container>
void	PMergeMe<Container>::setup() {
	fordJohnson();
	_recursiveLevels -= 1;
	while (_recursiveLevels > 0) {
		setMainAndPend();
		insertPendIntoMain();
		_boundaryNumber.clear();
		_fj.erase(_fj.begin(), _fj.begin() + _mainVec.size());
		_fj.insert(_fj.begin(), _mainVec.begin(), _mainVec.end());
		_recursiveLevels--;
		_mainVec.clear();
		_pendVec.clear();
	}
}

template <typename Container>
void	PMergeMe<Container>::printBefore() {
	std::cout << GREEN << "Before: ";
	for (size_t i = 0; i < _fj.size(); i++)
		std::cout << _fj[i] << " ";
	std::cout << RESET << std::endl;
}

template <typename Container>
void	PMergeMe<Container>::printAfter() {
	std::cout << GREEN << "After: ";
	for (size_t i = 0; i < _fj.size(); i++)
		std::cout << _fj[i] << " ";
	std::cout << RESET << std::endl;
}

template <typename Container>
PMergeMe<Container>::~PMergeMe() {}

template <typename Container>
void PMergeMe<Container>::parseInput(char *av) {
	std::string			str;
	std::stringstream	ss;
	char				*endptr = NULL;
	ss << av;
	while (ss >> str) {
		long	num;
		errno = 0;
		num = std::strtol(str.c_str(), &endptr, 10);
		if (*endptr || errno == ERANGE || num < 0 || num > INT_MAX)
			throw std::runtime_error(str + " :Invalid input!");
		this->_fj.push_back(static_cast<int>(num));
	}
	checkDuplicates();
}

template <typename Container>
void PMergeMe<Container>::checkDuplicates() {
	Container copy = _fj;
	std::sort(copy.begin(), copy.end());

	for (size_t i = 1; i < copy.size(); ++i) {
		if (copy[i] == copy[i - 1]) {
			std::stringstream ss;
			ss << copy[i];
			throw std::runtime_error("Duplicate value found: " + ss.str());
		}
	}
}

template <typename Container>
void	PMergeMe<Container>::insertPendIntoMain() {
	if (_pendVec.size() == 0)
		return ;
	calculateJacobsthal();
	setBlockSize();
	defineBoundaries();
	size_t	lastIndex =  _firstIndex; // which is actually the last index of the first block
	while (!_pendVec.empty()) {
		for (size_t i = 0; i < _jacobsthalVec.size(); i++) {
			size_t j = _jacobsthalVec[i];
			while (j > 0) {
				size_t curIndex = j - 1;
				// look for defined block and define index again
				checkBoundaryIndex(curIndex);
				size_t start = curIndex * _blockSize;
				size_t end = lastIndex + curIndex * _blockSize;
				Container blockToInsert(_pendVec.begin() + start, _pendVec.begin() + end + 1);
				binaryInsertBlock(blockToInsert);
				_boundaryNumber.erase(_boundaryNumber.begin() + curIndex);
				_pendVec.erase(_pendVec.begin() + start, _pendVec.begin() + end + 1);
				j--;
			}
		}
	}
}

/*This function is used to define the boundary in the beginning of the insertion.
Since both vectors are going to change while this is being executed, I need to keep track of what is the number of the border*/
template <typename Container>
void	PMergeMe<Container>::defineBoundaries() {
	for (size_t i = 0; i < _pendVec.size(); i+= _blockSize)
		_boundaryNumber.push_back(_mainVec[_firstIndex + _blockSize + i]);
}

/*After defining the boundary in the previous function, now we need to search where is that number again in each iteration.*/
template <typename Container>
void	PMergeMe<Container>::checkBoundaryIndex(size_t curIndex) {
	typename Container::iterator it = std::find(_mainVec.begin(), _mainVec.end(), _boundaryNumber[curIndex]);
	_boundaryIndex = it - _mainVec.begin();
}

/*After calculating what is the pend vec block, this function inserts into main*/
template <typename Container>
void PMergeMe<Container>::binaryInsertBlock(const Container& block)
{
	int key = block[block.size() - 1]; // last element of block
	size_t left = 0;
	size_t right = ((_boundaryIndex + 1) / _blockSize); // number of blocks that are in main to compare
	while (left < right)
	{
		comparisons++;
		size_t mid = (left + right) / 2;
		int midValue = _mainVec[mid * _blockSize + _blockSize - 1]; // last element of mid block
		if (midValue < key)
			left = mid + 1;
		else
			right = mid;
	}

	// Insert block at the correct position
	_mainVec.insert(_mainVec.begin() + left * _blockSize, block.begin(), block.end());
}

/*Calculates the number and order of which pend block is going to be inserted into main.*/
template <typename Container>
void PMergeMe<Container>::calculateJacobsthal() {
	_jacobsthalVec.clear();

	size_t n = std::pow(2, _recursiveLevels);
	size_t blockSize = n / 2;
	int numberOfBlocks = _pendVec.size() / blockSize;
	if (numberOfBlocks == 0)
		return;
	Container jac;
	jac.push_back(0);  // J0
	jac.push_back(1);  // J1

	while (jac.back() <= numberOfBlocks + 1) {
		size_t next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
		jac.push_back(next);
	}

	// We start at J3 since B1 is already in main.
	size_t i = 3;

	while (numberOfBlocks > 0) {
		int diff = jac[i] - jac[i - 1]; // The difference between each Jacobsthal, to know how many blocks are going to be inserted in that iteration
		if (diff > numberOfBlocks)
			diff = numberOfBlocks;
		_jacobsthalVec.push_back(diff);
		numberOfBlocks -= diff;
		i++;
	}
}

/*In each iteration, I need to set all As and Bs into _mainVec and _pendVec.
This is checked by 2 pairs at once, to check which one is the pend and which one is the main*/
template <typename Container>
void PMergeMe<Container>::setMainAndPend() {
	setBlockSize();
	size_t start = 0;

	while (_secondIndex < _fj.size()) {
		if (start == 0) // to insert B1 Block only in the first iteration
			_mainVec.insert(_mainVec.end(), _fj.begin() + start, _fj.begin() + start + _blockSize);
		else // insert all Bs into pendVec
			_pendVec.insert(_pendVec.end(), _fj.begin() + start, _fj.begin() + start + _blockSize);
		// insert all As into mainVec
		_mainVec.insert(_mainVec.end(), _fj.begin() + start + _blockSize, _fj.begin() + start + 2 * _blockSize);
		// Move to next block pair
		start += 2 * _blockSize;
		_firstIndex += 2 * _blockSize;
		_secondIndex += 2 * _blockSize;
	}
	if (_firstIndex < _fj.size()) { // if the number of pairs is odd, the last one is added to pendVec
		size_t remaining = std::min(_blockSize, _fj.size() - start);
		_pendVec.insert(_pendVec.end(), _fj.begin() + start, _fj.begin() + start + remaining);
	}
}

template <typename Container>
Container PMergeMe<Container>::fordJohnson() {
	size_t n = std::pow(2, _recursiveLevels);
	if (n > _fj.size())
		return (_fj);
	setBlockSize();
	size_t start = 0;
	while (_firstIndex < _fj.size() && _secondIndex < _fj.size()) {
		comparisons++;
		if (_fj[_firstIndex] > _fj[_secondIndex])
			std::swap_ranges(_fj.begin() + start, _fj.begin() + start + _blockSize, _fj.begin() + start + _blockSize);
		start += n;
		_firstIndex += n;
		_secondIndex += n;
	}
	_recursiveLevels++;
	return (fordJohnson());
}

/*Besides setting the size of the block, it also sets the first and second index, which are actually the last index of the first pair
and the last index of the second pair, since the comparisons are always made between these 2 numbers*/
template <typename Container>
void	PMergeMe<Container>::setBlockSize() {
	size_t n = std::pow(2, _recursiveLevels);
	_firstIndex = n / 2 - 1;
	_secondIndex = n - 1;
	_blockSize = n / 2;
}

template <typename Container>
size_t	PMergeMe<Container>::getNumberOfElements() {
	return (_fj.size());
}

/*Since all the functions are defined in the .cpp, these 2 declarations tell the compiler to create the 2 different classes using the template*/
template class PMergeMe<std::vector<int> >;
template class PMergeMe<std::deque<int> >;