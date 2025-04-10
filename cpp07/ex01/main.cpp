#include "iter.hpp"

template<typename T>
void	increment(T& value) {
	value++;
}

template<typename T>
void	print(const T& info) {
	std::cout << info << std::endl;
}

void	print2(int info) {
	std::cout << info << std::endl;
}

int main(void) {
	int arr_num[] = {1, 2, 3, 4, 5};
	std::cout << "Before:\n\n";
	iter(arr_num, 5, print<int>);
	std::cout << "\n\nAfter:\n\n";
	iter(arr_num, 5, increment<int>);
	iter(arr_num, 5, print<int>);
	std::cout << "Printing without explicitly mentioning type\n\n";
	iter(arr_num, 5, print2);
}