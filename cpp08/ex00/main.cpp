#include "easyfind.hpp"


int main(void) {
	std::cout << YELLOW << "-----Testing vector-----" << RESET << std::endl;
	try {
		std::vector<int> v1;
		for (int i = 0; i < 10; i++)
			v1.push_back(i * 10);
		std::vector<int>::iterator i = easyfind(v1, 10);
		std::cout << GREEN << "Number found: " << RESET << *i << std::endl;
		std::vector<int>::iterator j = easyfind(v1, 20);
		std::cout << GREEN << "Number found: " << RESET << *j << std::endl;
		std::vector<int>::iterator k = easyfind(v1, 200);
		std::cout << GREEN << "Number found: " << RESET << *k << std::endl;	
	}
	catch (std::runtime_error &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "-----Testing list-----" << RESET << std::endl;
	try {
		std::list<int> l1;
		for (int i = 0; i < 10; i++)
			l1.push_front(i * 10);
		std::list<int>::iterator l = easyfind(l1, 10);
		std::cout << GREEN << "Number found: " << RESET << *l << std::endl;
		std::list<int>::iterator m = easyfind(l1, 20);
		std::cout << GREEN << "Number found: " << RESET << *m << std::endl;
		std::list<int>::iterator n = easyfind(l1, 50);
		std::cout << GREEN << "Number found: " << RESET << *n << std::endl;
		std::list<int>::iterator o = easyfind(l1, 200);
		std::cout << GREEN << "Number found: " << RESET << *o << std::endl;	
	}
	catch (std::runtime_error &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << "-----Testing deque-----" << RESET << std::endl;
	try {
		std::deque<int> l1;
		for (int i = 0; i < 10; i++)
			l1.push_front(i * 10);
		std::deque<int>::iterator l = easyfind(l1, 10);
		std::cout << GREEN << "Number found: " << RESET << *l << std::endl;
		std::deque<int>::iterator m = easyfind(l1, 20);
		std::cout << GREEN << "Number found: " << RESET << *m << std::endl;
		std::deque<int>::iterator n = easyfind(l1, 50);
		std::cout << GREEN << "Number found: " << RESET << *n << std::endl;
		std::deque<int>::iterator o = easyfind(l1, 200);
		std::cout << GREEN << "Number found: " << RESET << *o << std::endl;	
	}
	catch (std::runtime_error &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}