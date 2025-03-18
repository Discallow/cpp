/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:20:00 by discallow         #+#    #+#             */
/*   Updated: 2025/03/18 00:21:29 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery Creation Form", 145, 137) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), 
	_target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other.getName(), 
	other.getGradeToSign(), other.getGradeToExec()), _target(other._target) {
	
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
	return ("Failed trying to create file!");
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::string	replaceos = this->_target;
	replaceos.append("_shrubbery");
	std::ofstream	os(replaceos.c_str());
	if (!os.is_open())
		throw FileOpenException();
	os << "      /\\      " << std::endl;
	os << "     /\\*\\     " << std::endl;
	os << "    /\\O\\*\\    " << std::endl;
	os << "   /*/\\/\\/\\   " << std::endl;
	os << "  /\\O\\/\\*\\/\\  " << std::endl;
	os << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	os << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	os << "      ||      " << std::endl;
	os << "      ||      " << std::endl;
	os << "      ||      " << std::endl;
	os << std::endl;

	os.close();
}