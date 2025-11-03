#include "Array.hpp"

template<typename T>
void print(const T& value) {
	std::cout << value << std::endl;
}

int main(void) {

	try {
		// ---------- Basic int array ----------
		Array<int> arr1(5);
		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = i * 10;

		std::cout << "arr1 contents:\n";
		for (unsigned int i = 0; i < arr1.size(); i++)
			print(arr1[i]);

		// ---------- Copy constructor test ----------
		std::cout << "\nTesting copy constructor...\n";
		Array<int> arrCopy(arr1);   // calls copy constructor
		for (unsigned int i = 0; i < arrCopy.size(); i++)
			print(arrCopy[i]);

		arrCopy[0] = 999;
		std::cout << "\nAfter modifying arrCopy[0]:\n";
		std::cout << "arr1[0] = " << arr1[0] << "\n";
		std::cout << "arrCopy[0] = " << arrCopy[0] << "\n";

		// ---------- String array ----------
		Array<std::string> arr2(10);
		for (unsigned int i = 0; i < arr2.size(); i++) {
			std::stringstream ss;
			ss << i;
			arr2[i] = ss.str() + ": string";
		}

		std::cout << "\narr2 contents:\n";
		for (unsigned int i = 0; i < arr2.size(); i++)
			print(arr2[i]);

		// ---------- Assignment operator test ----------
		std::cout << "\nTesting assignment operator...\n";
		Array<std::string> arrAssigned;
		arrAssigned = arr2;   // calls operator=
		for (unsigned int i = 0; i < arrAssigned.size(); i++)
			print(arrAssigned[i]);

		arrAssigned[0] = "modified string 0";
		std::cout << "\nAfter modifying arrAssigned[0]:\n";
		std::cout << "arr2[0] = " << arr2[0] << "\n";
		std::cout << "arrAssigned[0] = " << arrAssigned[0] << "\n";

		// ---------- Exception test ----------
		std::cout << "\nThrowing exception test:\n";
		Array<double> arr3(10);
		for (unsigned int i = 0; i < arr3.size(); i++)
			arr3[i] = i * 1.5;
		for (unsigned int i = 0; i < arr3.size() + 1; i++)  // triggers exception
			print(arr3[i]);
	}
	catch (const std::exception &e){
		std::cerr << "Exception found: " << e.what() << std::endl;
	}
	return (0);
}