/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:35:32 by discallow         #+#    #+#             */
/*   Updated: 2025/03/18 00:25:45 by discallow        ###   ########.fr       */
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
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void) {
	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
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

void	Bureaucrat::signForm(AForm& f) {
	try {
		f.beSigned(*this);
		std::cout << GREEN << this->_name << " signed " << f.getName() << RESET << std::endl;
	}
	catch (const std::exception& error) {
		std::cerr << RED << this->_name << " couldn't sign " << f.getName() << " because: " 
			<< error.what() << RESET << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << GREEN << this->_name << " executed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception &error) {
		std::cerr << RED << this->_name << " couldn't execute " << form.getName() << " because: " 
			<< error.what() << RESET << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}