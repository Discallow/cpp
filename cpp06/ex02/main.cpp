#include "Base.hpp"

Base*	generate() {
	srand(time(0));
	int	result = rand() % 3;
	if (result == 0)
		return (new (A));
	else if (result == 1)
		return (new (B));
	else
		return (new (C));
}

void	identify(Base* base) {
	if (dynamic_cast<A*>(base))
		std::cout << "A\n";
	else if(dynamic_cast<B*>(base))
		std::cout << "B\n";
	else
		std::cout << "C\n";
}

void	identify(Base& base) {
	try {
		(void)dynamic_cast<A&>(base);
		std::cout << "A\n";
		return ;
	} catch (...) {
			try {
				(void)dynamic_cast<B&>(base);
				std::cout << "B\n";
				return ;
			} catch (...) {
				try {
					(void)dynamic_cast<C&>(base);
					std::cout << "C\n";
					return ;
			} catch (...) {
				std::cout << "Error: Unknown type\n";
			}
		}
	}
}

int main() {
	Base* base = generate();
	Base& ref = *base;
	identify(base);
	identify(ref);

	delete base;
} 