#include "RPN.hpp"

int	makeOperation(const std::string& tmp, int left, int right) {
	if (tmp == "+")
		return (left + right);
	else if (tmp == "-")
		return (left - right);
	else if (tmp == "*")
		return (left * right);
	else if (right == 0)
		throw std::runtime_error("Error");
	return (left / right);
}

int convert(std::stack<int>& RPN, const std::string& input) {
	std::string			tmp;
	std::istringstream	ss(input);
	int					result;

	while (ss >> tmp) {
		if (std::isdigit(tmp[0]) && tmp.size() == 1) {
			int value;
			std::istringstream convert(tmp);
			convert >> value;
			RPN.push(value);
		}
		else if ((tmp == "+" || tmp == "-" || tmp == "/" || tmp == "*") 
			&& tmp.size() == 1) {
			if (RPN.size() < 2)
				throw std::runtime_error("Error");
			int rightOperand = RPN.top();
			RPN.pop();
			int	leftOperand = RPN.top();
			RPN.pop();
			result = makeOperation(tmp, leftOperand, rightOperand);
			RPN.push(result);
		}
		else
			throw std::runtime_error("Error");
	}
	if (RPN.size() != 1)
		throw std::runtime_error("Error");
	result = RPN.top();
	RPN.pop();
	return (result);
} 