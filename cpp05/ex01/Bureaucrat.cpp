/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:35:32 by discallow         #+#    #+#             */
/*   Updated: 2025/03/16 03:54:44 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Bureaucrat"), _grade(1) {
	
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void) {
	
}

const std::string& Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::decrement() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::increment() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

void	Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &error) {
		std::cerr << this->_name << " coudln't sign " << f.getName() << " because " << error.what() << std::endl;
	}
	catch (const std::exception& error) {
		std::cerr << "Generic std::exception caught: " << error.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}