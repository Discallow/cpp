/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:59:47 by discallow         #+#    #+#             */
/*   Updated: 2025/03/18 00:12:40 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << "======= 1. Bureaucrats with invalid grades =======\n";
	try {
		Bureaucrat failLow("FailLow", 151);
	} catch (const std::exception& e) {
		std::cerr << "Couldn't create a Bureaucrat object because: " << e.what() << std::endl;
	}

	try {
		Bureaucrat failHigh("FailHigh", 0);
	} catch (const std::exception& e) {
		std::cerr << "Couldn't create a Bureaucrat object because: " << e.what() << std::endl;
	}
	
	std::cout << "\n\n";

	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 150);
	Bureaucrat mid("Mid", 72);

	std::cout << "======= 2. PresidentialPardonForm =======\n"; 
	AForm* pardon = new PresidentialPardonForm("Alice");
	AForm* failedPardon = new PresidentialPardonForm("Diogo");

	mid.signForm(*pardon);  // Should fail (72 >= 25 sign grade required)
	boss.signForm(*pardon);
	boss.executeForm(*pardon);
	worker.executeForm(*pardon);
	boss.executeForm(*failedPardon); // Should fail because it wasnt signed

	delete pardon;
	delete failedPardon;
	
	std::cout << "\n\n";

	std::cout << "======= 3. RobotomyRequestForm =======\n";
	AForm* robotomy = new RobotomyRequestForm("Bob");

	mid.signForm(*robotomy);
	mid.executeForm(*robotomy); 
	boss.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << "\n\n";
	
	std::cout << "======= 4. ShrubberyCreationForm =======\n";
	AForm* shrubbery = new ShrubberyCreationForm("Garden");

	worker.signForm(*shrubbery);
	mid.signForm(*shrubbery);
	mid.executeForm(*shrubbery);
	worker.executeForm(*shrubbery);
	delete shrubbery;

	return (0);
}
