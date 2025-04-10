#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <deque>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define WHITE	"\033[37m"
# define BLACK	"\033[30m"
# define YELLOW	"\033[33m"
# define CYAN	"\033[36m"
# define GRAY	"\033[90m"
# define RESET	"\033[0m"

template<typename T>
typename T::iterator	easyfind(T& container, int n) {
	typename T::iterator num = std::find(container.begin(), container.end(), n);
	if (num == container.end())
		throw std::runtime_error("Number not found in the container!");
	return (num);
}

#endif
