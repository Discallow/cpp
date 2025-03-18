/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 03:10:59 by discallow         #+#    #+#             */
/*   Updated: 2025/03/18 00:25:01 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("unknown"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {
	
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec): _name(name)
, _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& other):_name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
	
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm(void) {

}

const char* AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade too low!");
}

const char* AForm::FormAlreadySigned::what(void) const throw() {
	return ("Form was already signed!");
}

const char* AForm::FormNotSigned::what(void) const throw() {
	return ("Form isn't signed!");
}

void	AForm::beSigned(Bureaucrat& b) {
	if (!_isSigned && b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else if (_isSigned)
		throw AForm::FormAlreadySigned();
	else
		throw AForm::GradeTooLowException();
}

std::string	AForm::getName() const {
	return (_name);
}

bool	AForm::getIsSigned() const {
	return (_isSigned);
}

int	AForm::getGradeToExec() const {
	return (_gradeToExec);
}

int AForm::getGradeToSign() const {
	return (_gradeToSign);
}

std::ostream& operator<<(std::ostream& os, AForm& form) {
	os << "Form name: " << form.getName() << std::endl;
	os << "Form status: " << form.getIsSigned() << std::endl;
	os << "Form grade to sign value: " << form.getGradeToSign() << std::endl;
	os << "Form grade to execute value: " << form.getGradeToExec() << std::endl;
	
	return (os);
}
