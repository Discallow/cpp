/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:20:00 by discallow         #+#    #+#             */
/*   Updated: 2025/03/18 00:30:04 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request Form", 72, 45) {
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), 
	_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other.getName(), 
	other.getGradeToSign(), other.getGradeToExec()), _target(other._target) {
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	
}

const char* RobotomyRequestForm::RobotomyFailedException::what() const throw() {
	return ("Error while trying to robotomize!");
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	srand(time(0));
	int randomNumber = rand() % 2;
	std::cout << YELLOW << "BzzzzZZz... Bzzzzzz..." << RESET << std::endl;
	if (!randomNumber)
		throw RobotomyFailedException();
	std::cout << GREEN << _target << " was robotomized successfully!" << RESET << std::endl;
}