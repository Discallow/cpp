#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define WHITE	"\033[37m"
# define BLACK	"\033[30m"
# define YELLOW	"\033[33m"
# define CYAN	"\033[36m"
# define GRAY	"\033[90m"
# define RESET	"\033[0m"

template<typename T, typename Func>
void	iter(T* array, const size_t length, Func func) {
	if (!array)
		return ;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif