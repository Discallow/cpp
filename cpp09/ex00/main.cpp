#include "BitcoinExchange.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << RED << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}
	std::ifstream file(av[1]);
	if (!file) {
		std::cerr << RED << "Error: could not open file." << std::endl;
		return (1);
	}
	try {
		std::map<std::string, std::string> Converter;
		Converter = loadCsv();
		convertBtc(file, Converter);
	}
	catch(std::runtime_error &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	return (0);
}