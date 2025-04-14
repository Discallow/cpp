#include "Span.hpp"

Span::Span(): _len(0) {}

Span::~Span() {}

Span::Span(unsigned int len): _len(len) {}

Span::Span(const Span& other): _len(other._len), _v1(other._v1) {}

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		this->_len = other._len;
		this->_v1 = other._v1;
	}
	return (*this);
}

const char* Span::WrongIndexException::what() const throw() {
	return ("You can't add more numbers!\n");
}

const char* Span::NoSpanFound::what() const throw() {
	return ("There aren't enough numbers to calculate the shortest/longest span!\n");
}

void	Span::addNumber(int num) {
	if (_v1.size() >= _len)
		throw WrongIndexException();
	_v1.push_back(num);
}

int	Span::shortestSpan() const {
	if (_v1.size() < 2)
		throw NoSpanFound();
	std::vector<int> temp = _v1;
	std::sort(temp.begin(), temp.end());
	int	minSpan = std::abs(temp[1] - temp[0]);
	for (unsigned int i = 0; i < temp.size() - 1; i++) {
		int	newSpan = std::abs(temp[i + 1] - temp[i]);
		if (newSpan < minSpan)
			minSpan = newSpan;
	}
	return (minSpan);
}

int	Span::longestSpan() const {
	if (_v1.size() < 2)
		throw NoSpanFound();
	int min = *std::min_element(_v1.begin(), _v1.end());
	int max = *std::max_element(_v1.begin(), _v1.end());
	return (max - min);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	size_t rangeSize = std::distance(begin, end);
	if (_v1.size() + rangeSize > _len)
		throw WrongIndexException();
	_v1.insert(_v1.end(), begin, end);
}
