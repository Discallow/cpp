#include "RPN.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << RED << "Invalid number or arguments" << std::endl;
		return (1);
	}
	try {
		std::stack<int> RPN;
		int	result;
		result = convert(RPN, std::string(av[1]));
		std::cout << GREEN << result << std::endl;
	}
	catch(std::runtime_error &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}