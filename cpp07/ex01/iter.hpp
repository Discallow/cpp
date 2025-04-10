#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T, typename Func>
void	iter(T* array, int length, Func func) {
	if (!func || !array)
		return ;
	for (int i = 0; i < length; i++)
		func(array[i]);
}

#endif