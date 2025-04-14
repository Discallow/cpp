#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <stack>
#include <iterator>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define WHITE	"\033[37m"
# define BLACK	"\033[30m"
# define YELLOW	"\033[33m"
# define CYAN	"\033[36m"
# define GRAY	"\033[90m"
# define RESET	"\033[0m"

template<typename T, typename Container = std::deque<T> >
class	MutantStack: public std::stack<T, Container> {
	public:
		MutantStack(): std::stack<T, Container>() {}
		virtual ~MutantStack() {}
		MutantStack(const MutantStack& other): std::stack<T, Container>(other) {}
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return (*this);
		}
		typedef typename Container::iterator iterator;

		iterator begin() { 
			return (this->c.begin());
		}
		iterator end() { 
			return (this->c.end());
		}
};

#endif