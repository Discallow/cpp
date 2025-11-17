#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <sstream>
# include <string>
# include <exception>
# include <deque>
# include <climits>
# include <cerrno>
# include <unistd.h>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define WHITE	"\033[37m"
# define BLACK	"\033[30m"
# define YELLOW	"\033[33m"
# define CYAN	"\033[36m"
# define GRAY	"\033[90m"
# define RESET	"\033[0m"

extern int	comparisons;

class PMergeMe {
	private:
		size_t				_firstIndex;
		size_t				_secondIndex;
		std::vector<int>	_mainVec;
		std::vector<int>	_pendVec;
		std::vector<int>	_fj;
		std::vector<int>	_jacobsthalVec;
		std::vector<int>	_matchingMainIndex;
		int					_recursiveLevels;
		size_t				_curIndex;
	public:
		PMergeMe();
		PMergeMe(char *av);
		~PMergeMe();
		size_t				totalComparisons;
		std::vector<int>	fordJohnson();
		void				parseInput(char *av);
		void				setMainAndPend();
		void				insertPendIntoMain();
		void				calculateJacobsthal();
		void				defineBoundaries();
		void				binaryInsertBlock(const std::vector<int>& block, size_t blockSize, size_t numbersInserted);

};

#endif