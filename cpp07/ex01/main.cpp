#include "iter.hpp"

template<typename T>
void	increment(T& value) {
	value++;
}

template<typename T>
void	print(const T& info) {
	std::cout << CYAN << info << RESET << std::endl;
}

void	print2(int info) {
	std::cout << CYAN << info << RESET << std::endl;
}

int main(void) {
	int arr_num[] = {1, 2, 3, 4, 5};
	size_t size = sizeof(arr_num) / sizeof(arr_num[0]);
	std::cout << YELLOW << "Before:\n\n" << RESET;
	iter(arr_num, size, print<int>); // the third parameter expands to void (*)(const int&)
	std::cout << YELLOW << "\nAfter:\n\n" << RESET;
	iter(arr_num, size, increment<int>); // the thir parameter expands to void (*)(int&)
	iter(arr_num, size, print<int>); // the third parameter expands to void (*)(const int&)
	std::cout << YELLOW << "\nPrinting without explicitly mentioning type\n\n" << RESET;
	iter(arr_num, size, print2); // the third parameter expands to void (*)(int)
}