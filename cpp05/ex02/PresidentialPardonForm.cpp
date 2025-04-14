/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:20:00 by discallow         #+#    #+#             */
/*   Updated: 2025/04/13 20:00:04 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("Presidential Pardon Form", 25, 5) {
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), 
	_target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other.getName(), 
	other.getGradeToSign(), other.getGradeToExec()), _target(other._target) {
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();	
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << CYAN << _target << " has been'd pardoned by Zaphod Beeblebrox!" << RESET << std::endl;
}