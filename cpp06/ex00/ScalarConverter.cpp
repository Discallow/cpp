/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:02:28 by discallow         #+#    #+#             */
/*   Updated: 2025/03/31 11:06:42 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string& input) {
	return (input.size() == 1 && !std::isdigit(input[0]));
}

static bool isInt(const std::string& input) {
	if (input.empty())
		return (false);

	const char* s = input.c_str();
	char* endptr = NULL;
	errno = 0;
	long result = std::strtol(s, &endptr, 10);
    if (s == endptr || *endptr || errno == ERANGE 
			|| result > INT_MAX || result < INT_MIN)
		return (false);
	return (true);
}

static bool isFloat(const std::string& input) {
	if (input.empty() || input[input.length() - 1] != 'f')
		return (false);
	char* endptr = NULL;
	errno = 0;
	float result = std::strtof(input.c_str(), &endptr);
	(void)result;
	if (*endptr != 'f' || *(endptr + 1) != '\0' 
			|| errno == ERANGE)
		return (false);
	return (true);
}

static bool isDouble(const std::string& input) {
	if (input.empty())
		return (false);
	char* endptr = NULL;
	errno = 0;
	double result = std::strtod(input.c_str(), &endptr);
	(void)result;
	if (*endptr	|| errno == ERANGE)
		return (false);
	return (true);
}

static int	validateInput(const std::string& input) {
	if (isChar(input))
		return (CHAR);
	if (isInt(input))
		return (INT);
	if (isFloat(input))
		return (FLOAT);
	if (isDouble(input))
		return (DOUBLE);
	return (INVALID);
}

static void printResults(double n) {
	if (std::isnan(n) || std::isinf(n) || n > std::numeric_limits<char>::max() || n < std::numeric_limits<char>::min())
		std::cout << "char: impossible\n";
	else if (std::isprint(static_cast<char>(n)))
		std::cout << "char: '" << static_cast<char>(n) << "'\n";
	else
		std::cout << "char: Non displayable\n";

	if (std::isnan(n) || std::isinf(n) || n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(n) << '\n';

	float f = static_cast<float>(n);
	if (std::isnan(f))
		std::cout << "float: nanf\n";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "float: +inff\n" : "float: -inff\n");
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\n";

	if (std::isnan(n))
		std::cout << "double: nan\n";
	else if (std::isinf(n))
		std::cout << (n > 0 ? "double: +inf\n" : "double: -inf\n");
	else
		std::cout << std::fixed << std::setprecision(1) << "double: " << n << '\n';
}

static void fromChar(const std::string& input) {
	char c = input[0];
	printResults(c);
}

static void fromInt(const std::string& input) {
	long n = std::strtol(input.c_str(), NULL, 10);
	printResults(n);
}

static void fromFloat(const std::string& input) {
	float n = std::strtof(input.c_str(), NULL);
	printResults(n);		
}

static void fromDouble(const std::string& input) {
	double n = std::strtod(input.c_str(), NULL);
	printResults(n);
}

static void fromInvalid(const std::string& input) {
	(void)input;
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: nanf\n";
	std::cout << "double: nan\n";
}

void ScalarConverter::convert(const std::string& input) {
	int	typeOfInput = validateInput(input);
	void (*functionPointer[])(const std::string&) = {&fromChar, &fromInt, &fromFloat, &fromDouble, &fromInvalid};
	functionPointer[typeOfInput](input);
}