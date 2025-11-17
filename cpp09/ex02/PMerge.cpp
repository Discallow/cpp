#include "PMerge.hpp"

int comparisons = 0;

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(char *av): _firstIndex(0), _secondIndex(0), _recursiveLevels(1), _curIndex(0) {
	parseInput(av);
	fordJohnson();
	_recursiveLevels -= 1;
	while (_recursiveLevels > 0) {
		setMainAndPend();
		std::cout << CYAN << "Main before: ";
		for (size_t i = 0; i < _mainVec.size(); i++)
			std::cout << _mainVec[i] << " ";
		std::cout << RESET << std::endl;
		std::cout << GRAY << "Pend before: ";
		for (size_t i = 0; i < _pendVec.size(); i++)
			std::cout << _pendVec[i] << " ";
		std::cout << RESET << std::endl;
		insertPendIntoMain();
		_recursiveLevels--;
		std::cout << CYAN << "Main after: ";
		for (size_t i = 0; i < _mainVec.size(); i++)
			std::cout << _mainVec[i] << " ";
		std::cout << RESET << std::endl;
		std::cout << GRAY << "Pend after: ";
		for (size_t i = 0; i < _pendVec.size(); i++)
			std::cout << _pendVec[i] << " ";
		std::cout << RESET << std::endl;
		std::cout << "jacobVec[i]: ";
		for (size_t i = 0; i < _jacobsthalVec.size(); i++)
			std::cout << _jacobsthalVec[i] << " ";
		std::cout << std::endl;
		std::cout << "boundaries: ";
		for (size_t i = 0; i < _matchingMainIndex.size(); i++)
			std::cout << _matchingMainIndex[i] << " ";
		std::cout << std::endl;
		std::cout << "comparisons: " << comparisons << std::endl;
		_mainVec.clear();
		_pendVec.clear();
	}
	std::cout << GREEN << "After: [ ";
	for (size_t i = 0; i < _fj.size(); i++)
		std::cout << _fj[i] << " ";
	std::cout << "]" << RESET << std::endl;
}

PMergeMe::~PMergeMe() {}

void PMergeMe::parseInput(char *av) {
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
	std::cout << GREEN << "Before: [ ";
	for (size_t i = 0; i < _fj.size(); i++)
		std::cout << _fj[i] << " ";
	std::cout << "]" << RESET << std::endl;
}

void	PMergeMe::insertPendIntoMain() {
	if (_pendVec.size() == 0)
		return ;
	calculateJacobsthal();
	defineBoundaries();
	size_t n = std::pow(2, _recursiveLevels);
	size_t	firstIndex = 0;
	size_t	lastIndex = n / 2 - 1;
	size_t	blockSize = n / 2;
	size_t	numbersInserted = 0;
	std::vector<int>	tempVec;
	//size_t start = 0;
	std::cout << "defining blocks: " << std::endl;
	std::cout << "lastIndex: " << lastIndex << " blockSize: " << blockSize << std::endl;
	for (size_t ctd = 0; ctd < _pendVec.size(); ctd += blockSize) {
		std:: cout << (_mainVec[lastIndex + blockSize + ctd]) << " ";
		tempVec.push_back(_mainVec[lastIndex + blockSize + ctd]);
	}
	std::cout << std::endl;
	while (!_pendVec.empty()) {
    for (size_t i = 0; i < _jacobsthalVec.size(); i++) {
		//std::cout << "jacobsthalVec[i]: " << _jacobsthalVec[i] << std::endl;
        size_t j = _jacobsthalVec[i];
		//define blocks

        while (j > 0) {
			// look for defined block and define index again
			size_t pos = 0;
			_curIndex = j - 1;
			for (size_t k = 0; k < _mainVec.size(); k++) {
				if (_mainVec[k] == tempVec[_curIndex]) {
					pos = k;
					std::cout << "numero aqui: " << _mainVec[pos] << std::endl;
					break ;
				}
			}
			
            size_t start = firstIndex + _curIndex * blockSize;
            size_t end   = lastIndex  + _curIndex * blockSize;
			/* std::cout << start << " " << _pendVec[start] << std::endl;
			std::cout << end << " " << _pendVec[end] << std::endl; */
            // INSERT INTO MAIN
			std::vector<int> blockToInsert(_pendVec.begin() + start, _pendVec.begin() + end + 1);
			binaryInsertBlock(blockToInsert, blockSize, pos);
			tempVec.erase(tempVec.begin() + _curIndex);
            // ERASE FROM PEND
            	_pendVec.erase(
                _pendVec.begin() + start,
                _pendVec.begin() + end + 1
            );
			//_matchingMainIndex.erase(_matchingMainIndex.begin());
			numbersInserted++;
            j--;
        }
		
    }
	}
	tempVec.clear();
	_fj.erase(_fj.begin(), _fj.begin() + _mainVec.size());
	_fj.insert(_fj.begin(), _mainVec.begin(), _mainVec.end());
}

void PMergeMe::binaryInsertBlock(const std::vector<int>& block, size_t blockSize, size_t numbersInserted)
{
    int key = block[block.size() - 1]; // last element of block
    size_t left = 0;
	std::cout << "numbersInsert: " << numbersInserted << " _curIndex: " << _curIndex << std::endl;
    size_t right = ((numbersInserted + 1) / blockSize); // number of blocks that are in main to compare
	std::cout << "Current main vec: " << std::endl;
	for (size_t i = 0; i < right * blockSize; i++)
		std::cout << _mainVec[i] << " ";
	std::cout << std::endl;
	std::cout << "Total main vec: " << std::endl;
	for (size_t i = 0; i < _mainVec.size(); i++)
		std::cout << _mainVec[i] << " ";
	std::cout << std::endl;
    while (left < right)
    {
		comparisons++;
        size_t mid = (left + right) / 2;
        int midValue = _mainVec[mid * blockSize + blockSize - 1]; // last element of mid block
		std::cout << "midValue: " << midValue << std::endl;
        if (midValue < key)
            left = mid + 1;
        else
            right = mid;
		std::cout << "left: " << left << std::endl;
    }

    // Insert block at the correct position
    _mainVec.insert(_mainVec.begin() + left * blockSize,
                   block.begin(),
                   block.end());
}


void	PMergeMe::defineBoundaries() {
	_matchingMainIndex.clear();
	size_t n = std::pow(2, _recursiveLevels);
	size_t blockSize = n / 2;
	int j = 1;
	for (size_t i = 0; i < _pendVec.size(); i+= blockSize) {
		//std::cout << "boundary number: " << _mainVec[j * blockSize] << std::endl;
		_matchingMainIndex.push_back(j);
		j++;
	}
}

void PMergeMe::calculateJacobsthal() {
    _jacobsthalVec.clear();

	//std::cout << "aqui" << _pendVec.size() << " " << _recursiveLevels << std::endl;
	size_t n = std::pow(2, _recursiveLevels);
	size_t blockSize = n / 2;
    size_t N = _pendVec.size() / blockSize;
    if (N == 0)
        return;

    // Build Jacobsthal numbers up to something > N+1
    std::vector<size_t> jac;
    jac.push_back(0);  // J0
    jac.push_back(1);  // J1

    while (jac.back() <= N + 1) {
        size_t next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
        jac.push_back(next);
    }

    // We start at J3 since B1 is already in main.
    size_t j = 3;

    size_t remaining = N;

    while (remaining > 0) {
		
        size_t diff = jac[j] - jac[j - 1];
        if (diff > remaining)
            diff = remaining;

        _jacobsthalVec.push_back(diff);

        remaining -= diff;
        j++;
    }
}


void PMergeMe::setMainAndPend() {
    size_t n = std::pow(2, _recursiveLevels);
    _firstIndex = n / 2 - 1;
    _secondIndex = n - 1;

    size_t start = 0;
    size_t blockSize = n / 2;

    while (_secondIndex < _fj.size()) {
        std::vector<int> firstBucket;
        std::vector<int> secondBucket;
        std::vector<int> thirdBucket;

        // Fill the buckets
        for (size_t i = 0; i < blockSize; ++i) {
            if (start == 0)
                firstBucket.push_back(_fj[start + i]);
            else
                thirdBucket.push_back(_fj[start + i]);

            secondBucket.push_back(_fj[start + blockSize + i]);
        }

        // Insert buckets into main/pend
        _mainVec.insert(_mainVec.end(), firstBucket.begin(), firstBucket.end());
        _mainVec.insert(_mainVec.end(), secondBucket.begin(), secondBucket.end());
        _pendVec.insert(_pendVec.end(), thirdBucket.begin(), thirdBucket.end());

        start += n;
        _firstIndex += n;
        _secondIndex += n;
    }

    // If a leftover third bucket exists at the end
    if (_firstIndex < _fj.size()) {
        size_t remaining = std::min(blockSize, _fj.size() - start);
        _pendVec.insert(_pendVec.end(), _fj.begin() + start, _fj.begin() + start + remaining);
    }
}


std::vector<int> PMergeMe::fordJohnson() {
	size_t n = std::pow(2, _recursiveLevels);
	if (n > _fj.size())
		return (_fj);
	_firstIndex = n / 2 - 1;
	_secondIndex = n - 1;
	size_t start = 0;
	size_t blockSize = n / 2;
	while (_firstIndex < _fj.size() && _secondIndex < _fj.size()) {
		comparisons++;
		if (_fj[_firstIndex] > _fj[_secondIndex]) {
			for (size_t i = 0; i < blockSize; ++i) {
				std::swap(_fj[start + i], _fj[start + blockSize + i]);
			}
		}
		start += n;
		_firstIndex += n;
		_secondIndex += n;
	}
	_recursiveLevels++;
	return (fordJohnson());
}