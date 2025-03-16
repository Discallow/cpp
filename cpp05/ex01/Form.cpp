/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:10:59 by discallow         #+#    #+#             */
/*   Updated: 2025/03/16 04:03:35 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("unknown"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	
}

Form::Form(const std::string name, int gradeToSign, int gradeToExec): _name(name)
, _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::~Form(void) {

}

const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low!");
}

void	Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::string	Form::getName() const {
	return (_name);
}

bool	Form::getIsSigned() const {
	return (_isSigned);
}

int	Form::getGradeToExec() const {
	return (_gradeToExec);
}

int Form::getGradeToSign() const {
	return (_gradeToSign);
}

std::ostream& operator<<(std::ostream& os, Form& form) {
	os << "Form name: " << form.getName() << std::endl;
	os << "Form status: " << form.getIsSigned() << std::endl;
	os << "Form grade to sign value: " << form.getGradeToSign() << std::endl;
	os << "Form grade to execute value: " << form.getGradeToExec() << std::endl;
	
	return (os);
}
