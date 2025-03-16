/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:11:00 by discallow         #+#    #+#             */
/*   Updated: 2025/03/16 02:54:10 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat b1("Alice", 1);
		std::cout << b1 << std::endl;

		std::cout << "Trying to increment Alice..." << std::endl;
		b1.increment();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Generic std::exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("Bob", 150);
		std::cout << b2 << std::endl;

		std::cout << "Trying to decrement Bob..." << std::endl;
		b2.decrement();
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Generic std::exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to create a Bureaucrat with grade 0..." << std::endl;
		Bureaucrat b3("Charlie", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Generic std::exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "Trying to create a Bureaucrat with grade 151..." << std::endl;
		Bureaucrat b4("Dave", 151);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Generic std::exception caught: " << e.what() << std::endl;
	}
	return (0);
}

