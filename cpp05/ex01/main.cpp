/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 06:11:00 by discallow         #+#    #+#             */
/*   Updated: 2025/03/16 04:06:41 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Bureaucrat highRank("HighRank", 5);
		Form permit("Permit", 10, 20);

		std::cout << "=== Test 1 ===" << std::endl;
		highRank.signForm(permit);
		std::cout << permit << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Test 1 Unexpected Exception: " << e.what() << std::endl;
    }

	try {
		Bureaucrat lowRank("LowRank", 50);
		Form topSecret("TopSecret", 10, 20);

		std::cout << "=== Test 2 ===" << std::endl;
		lowRank.signForm(topSecret);

		std::cout << topSecret << std::endl;
    }
	catch (const Form::GradeTooLowException& e) {
		std::cerr << "Test 2 Form::GradeTooLowException: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Test 2 Unexpected Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "=== Test 3 ===" << std::endl;
		Form invalid("ImpossibleForm", 0, 100);
	}
	catch (const Form::GradeTooHighException& e) {
		std::cerr << "Test 3 Form::GradeTooHighException: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Test 3 Unexpected Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "=== Test 4 ===" << std::endl;
		Form invalid("InvalidLowForm", 151, 200);
	}
	catch (const Form::GradeTooLowException& e) {
		std::cerr << "Test 4 Form::GradeTooLowException: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Test 4 Unexpected Exception: " << e.what() << std::endl;
	}
    return (0);
}
