#include "Span.hpp"

int main(void) {
	std::cout << YELLOW << "----- Testing Span -----" << RESET << std::endl;

	try {
		Span sp1(1000000);
		for (int i = 0; i < 5; ++i)
			sp1.addNumber(i * 10);

		std::cout << GREEN << "sp1 shortest span: " << RESET << sp1.shortestSpan() << std::endl;
		std::cout << GREEN << "sp1 longest span: " << RESET << sp1.longestSpan() << std::endl;

		Span sp2(sp1);
		std::cout << CYAN << "sp2 (copy of sp1) shortest span: " << RESET << sp2.shortestSpan() << std::endl;
		std::cout << CYAN << "sp2 (copy of sp1) longest span: " << RESET << sp2.longestSpan() << std::endl;

		Span sp3(1000000);
		sp3 = sp1;
		std::cout << GRAY << "sp3 (assigned from sp1) shortest span: " << RESET << sp3.shortestSpan() << std::endl;
		std::cout << GRAY << "sp3 (assigned from sp1) longest span: " << RESET << sp3.longestSpan() << std::endl;

		std::vector<int> extra;
		for (int i = 0; i <= 10000; i++)
			extra.push_back(i * 10);

		sp1.addRange(extra.begin(), extra.end());

		std::cout << YELLOW << "After addRange to sp1:" << RESET << std::endl;
		std::cout << BLUE << "sp1 shortest span: " << RESET << sp1.shortestSpan() << std::endl;
		std::cout << BLUE << "sp1 longest span: " << RESET << sp1.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return (0);
}
