#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define WHITE	"\033[37m"
# define BLACK	"\033[30m"
# define YELLOW	"\033[33m"
# define CYAN	"\033[36m"
# define GRAY	"\033[90m"
# define RESET	"\033[0m"

class Span {
	private:
		unsigned int		_len;
		std::vector<int>	_v1;
	public:
		Span();
		Span(unsigned int len);
		~Span();
		Span(const Span& other);
		Span&	operator=(const Span& other);
		class WrongIndexException: public std::exception {
			public:
				const char* what() const throw();
		};
		class NoSpanFound: public std::exception {
			public:
				const char* what() const throw();
		};
		void	addNumber(int num);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

#endif