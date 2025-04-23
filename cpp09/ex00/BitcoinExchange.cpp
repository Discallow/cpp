#include "BitcoinExchange.hpp"

static std::string	trim(std::string& str) {
	str.erase(0, str.find_first_not_of(" \t\r\n\v\f"));
	str.erase(str.find_last_not_of(" \t\r\n\v\f") + 1);
	return str;
}

static bool	isValidNumber(const std::string& str) {
	std::istringstream	result(str);
	char				leftover;
	float				value;
	if (!(result >> value) || (result >> leftover))
		return (false);
	else if (value > 1000)
		throw std::runtime_error("too large a number.");
	else if (value < 0)
		throw std::runtime_error("not a positive number.");
	return (true);
}

static bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool	isValidDate(const std::string& str) {
	std::istringstream	date(str);
	int					year, month, day;
	char				dash1, dash2, leftover;
	
	if (!(date >> year >> dash1 >> month >> dash2 >> day)
		|| (date >> leftover))
		return (false);
	if (year < 1900 || year > 9999)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day < 1 || day > 31)
				return false;
			break ;
		case 4: case 6: case 9: case 11:
			if (day < 1 || day > 30)
				return (false);
			break ;
		case 2:
			if (isLeapYear(year) && (day < 1 || day > 29))
				return (false);
			else if (!isLeapYear(year) && (day < 1 || day > 28))
				return (false);
			break ;
	}
	return (true);
}

static bool isFloat(const std::string& input) {
	if (input.empty())
		return (false);
	char* endptr = NULL;
	errno = 0;
	float result = std::strtof(input.c_str(), &endptr);
	(void)result;
	if (errno == ERANGE)
		throw std::runtime_error("number out of range.");
    if (*endptr)
		return (false);
	return (true);
}

static bool isInt(const std::string& input) {
	if (input.empty())
		return (false);

	const char* s = input.c_str();
	char* endptr = NULL;
	errno = 0;
	long result = std::strtol(s, &endptr, 10);
	(void)result;
	if (errno == ERANGE)
		throw std::runtime_error("number out of range.");
    if (s == endptr || *endptr)
		return (false);
	return (true);
}

void	displayResult(std::map<std::string, std::string> data, std::string& key, std::string& value) {
	
	std::map<std::string, std::string>::iterator it = data.lower_bound(key);
	float		num, num2;
	if (it == data.end() || it->first != key) {
		if (it == data.begin())
			throw std::runtime_error(key + ": date not found!");
		--it;
	}
	trim(it->second);
	trim(value);
	trim(key);
	std::istringstream ss1(it->second);
	std::istringstream ss2(value);
	if (!isInt(it->second) && !isFloat(it->second))
		throw std::runtime_error("bad input => " + it->second);
	ss1 >> num;
	if (!isInt(value) && !isFloat(value))
			throw std::runtime_error("bad input => " + value);
	ss2 >> num2;
	std::cout << key << " => " << value << " = " << std::setprecision(2) << num * num2 << std::endl;
}

std::map<std::string, std::string>	loadCsv(void) {
	std::map<std::string, std::string>	data;
	std::ifstream					file("data.csv");
	std::string						line, keyStr, valueStr;
	if (!file)
		throw std::runtime_error("Error opening file!");
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid file!");
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		if (std::getline(ss, keyStr, ',') && std::getline(ss, valueStr))
			data[keyStr] = valueStr;
		else
			throw (std::runtime_error("bad input => " + line));
	}
	return (data);
}

void	convertBtc(std::ifstream &file, std::map<std::string, std::string> data) {
	std::string	line, keyStr, valueStr;
	std::getline(file, line);
	if (line != "date | value")
		throw (std::runtime_error("bad input => " + line));
	while (std::getline(file, line)) {
		try {
			std::istringstream ss(line);
			if (std::getline(ss, keyStr, '|') && std::getline(ss, valueStr)) {
				if (!isValidDate(keyStr) || !isValidNumber(valueStr))
					throw std::runtime_error("bad input => " + line);
				displayResult(data, keyStr, valueStr);
			}
			else
				throw (std::runtime_error("bad input => " + line));
		}
		catch(std::runtime_error &e) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
}