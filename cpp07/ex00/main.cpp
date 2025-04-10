#include "whatever.hpp"

int main(void) {
	int a = 5, b = 10;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

	double x = 3.5, y = 7.2;
	std::cout << "\nBefore swap: x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout << "\nMin of (5, 10): " << ::min(5, 10) << std::endl;

	std::cout << "Min of (3.5, 7.2): " << ::min(3.5, 7.2) << std::endl;

	std::string str1 = "apple", str2 = "banana";
	std::cout << "Min of (\"apple\", \"banana\"): " << ::min(str1, str2) << std::endl;

	std::cout << "\nMax of (5, 10): " << ::max(5, 10) << std::endl;

	std::cout << "Max of (3.5, 7.2): " << ::max(3.5, 7.2) << std::endl;

	std::cout << "Max of (\"apple\", \"banana\"): " << ::max(str1, str2) << std::endl;

	return (0);
}