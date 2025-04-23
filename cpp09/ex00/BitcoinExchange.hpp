#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <exception>
#include <fstream>
#include <sstream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cerrno>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define WHITE	"\033[37m"
# define BLACK	"\033[30m"
# define YELLOW	"\033[33m"
# define CYAN	"\033[36m"
# define GRAY	"\033[90m"
# define RESET	"\033[0m"

void							convertBtc(std::ifstream &file, std::map<std::string, std::string>);
std::map<std::string, std::string>	loadCsv(void);

#endif