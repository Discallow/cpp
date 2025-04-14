#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	std::cout << GREEN << "Pushing elements into the stack..." << RESET << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << BLUE << "Pushing: " << i * 10 << RESET << std::endl;
		mstack.push(i * 10);
    }

	std::cout << YELLOW << "Iterating through the stack using iterators:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << WHITE << *it << RESET << " ";
	}
	std::cout << std::endl;

	MutantStack<int> mstackCopy(mstack);
	std::cout << GREEN << "Using the copy constructor:" << RESET << std::endl;
	std::cout << "Elements in the copied stack: ";
	for (MutantStack<int>::iterator it = mstackCopy.begin(); it != mstackCopy.end(); ++it) {
		std::cout << WHITE << *it << RESET << " ";
	}
	std::cout << std::endl;

	MutantStack<int> mstackAssign(mstack);
	mstackAssign = mstackCopy;
	std::cout << GREEN << "Using the assignment operator:" << RESET << std::endl;
	std::cout << "Elements in the assigned stack: ";
	for (MutantStack<int>::iterator it = mstackAssign.begin(); it != mstackAssign.end(); ++it) {
		std::cout << WHITE << *it << RESET << " ";
	}
	std::cout << std::endl;

	MutantStack<int, std::list<int> > stack2;
	stack2.push(30);
	stack2.push(40);

	std::cout << GREEN << "MutantStack with std::list:" << RESET << std::endl;
	for (MutantStack<int, std::list<int> >::iterator it = stack2.begin(); it != stack2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << YELLOW << "Popping elements from the original stack..." << RESET << std::endl;
	while (!mstack.empty()) {
		std::cout << RED << "Popped: " << mstack.top() << RESET << std::endl;
		mstack.pop();
	}
    return (0);
}
