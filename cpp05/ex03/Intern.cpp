/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:25:17 by discallow         #+#    #+#             */
/*   Updated: 2025/03/18 14:30:14 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	
}

Intern::~Intern(void) {
	
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return (*this);
}

static AForm* makePresidentialForm(const std::string form, const std::string target) {
	std::cout << L_GREEN << "Intern creates " << form << "." << RESET << std::endl;
	return (new PresidentialPardonForm(target));
}

static AForm* makeShrubberyForm(const std::string form, const std::string target) {
	std::cout << L_GREEN << "Intern creates " << form << "." << RESET << std::endl;
	return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomyForm(const std::string form, const std::string target) {
	std::cout << L_GREEN << "Intern creates " << form << "." << RESET << std::endl;
	return (new RobotomyRequestForm(target));
}

static AForm* errorForm(const std::string form, const std::string target) {
	(void)target;
	std::cout << B_RED << "Error while creating form. The type of form: \"" << form << "\" requested doesn't exist!"
	<< RESET << std::endl;
	return (NULL);
}

AForm* Intern::makeForm(const std::string form, const std::string target) {
	std::string options[] = {"shrubbery creation", "robotomy request", "presidential pardon", "error"};
	AForm* (*functionPointer[])(const std::string form, const std::string target) = {&makeShrubberyForm, &makeRobotomyForm, &makePresidentialForm, &errorForm};
	int i = 0;
	while (i < 3 && form != options[i])
		i++;
	return (functionPointer[i](form, target));
}
