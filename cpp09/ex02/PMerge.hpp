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
# include <sys/time.h>
# include <iomanip>

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

template <typename Container>
class PMergeMe {
	private:
		size_t				_firstIndex;
		size_t				_secondIndex;
		size_t				_blockSize;
		Container			_mainVec;
		Container			_pendVec;
		Container			_fj;
		Container			_jacobsthalVec;
		Container			_boundaryNumber;
		int					_recursiveLevels;
		size_t				_boundaryIndex;

	public:
		PMergeMe();
		~PMergeMe();

		Container			fordJohnson();
		void				setup();
		void				parseInput(char *av);
		void				checkDuplicates();
		void				setMainAndPend();
		void				insertPendIntoMain();
		void				calculateJacobsthal();
		void				defineBoundaries();
		void				binaryInsertBlock(const Container& block);
		void				setBlockSize();
		void				checkBoundaryIndex(size_t curIndex);
		void				printBefore();
		void				printAfter();

		size_t				getNumberOfElements();
};

#endif
