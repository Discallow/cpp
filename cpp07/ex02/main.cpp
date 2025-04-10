#include "Array.hpp"

template<typename T>
void	print(T& value) {
	std::cout << value << std::endl;
}

int main(void) {

	try {
		Array<int> arr1(5);
		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = i * 10;
		for (unsigned int i = 0; i < arr1.size(); i++)
			print(arr1[i]);

		Array<std::string> arr2(10);
		for (unsigned int i = 0; i < arr2.size(); i++) {
			std::stringstream ss;
			ss << i;
			arr2[i] = ss.str() + ": string";
		}
			
		for (unsigned int i = 0; i < arr2.size(); i++)
			print(arr2[i]);

		std::cout << "Throwing exception\n";
		Array<double> arr3(10);
		for (unsigned int i = 0; i < arr3.size(); i++)
			arr3[i] = i * 1.5;
		for (unsigned int i = 0; i < arr3.size() + 1; i++)
			print(arr3[i]);
	}
	catch (const std::exception &e){
		std::cerr << "Exception found: " << e.what() << std::endl;
	}

	return (0);
}