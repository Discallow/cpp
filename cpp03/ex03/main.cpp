/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:29:35 by arabelo-          #+#    #+#             */
/*   Updated: 2025/02/26 17:41:55 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

# ifndef RED_TEXT
#  define RED_TEXT "\033[0;31m"
# else
#  define RED_TEXT "\033[31m"
# endif

# ifndef GREEN_TEXT
#  define GREEN_TEXT "\033[0;32m"
# else
#  define GREEN_TEXT "\033[32m"
# endif

# ifndef YELLOW_TEXT
#  define YELLOW_TEXT "\033[0;33m"
# else
#  define YELLOW_TEXT "\033[0;33m"
# endif

# ifndef BLUE_TEXT
#  define BLUE_TEXT "\033[0;34m"
# else
#  define BLUE_TEXT "\033[0;34m"
# endif

# ifndef MAGENTA_TEXT
#  define MAGENTA_TEXT "\033[0;35m"
# else
#  define MAGENTA_TEXT "\033[0;35m"
# endif

# ifndef WHITE_TEXT
#  define WHITE_TEXT "\033[0;37m"
# else
#  define WHITE_TEXT "\033[0;37m"
# endif

# ifndef BLACK_BACKGROUND
#  define BLACK_BACKGROUND "\033[40m"
# else
#  define BLACK_BACKGROUND "\033[40m"
# endif

# ifndef RED_BACKGROUND
#  define RED_BACKGROUND "\033[41m"
# else
#  define RED_BACKGROUND "\033[41m"
# endif

# ifndef GREEN_BACKGROUND
#  define GREEN_BACKGROUND "\033[42m"
# else
#  define GREEN_BACKGROUND "\033[42m"
# endif

# ifndef YELLOW_BACKGROUND
#  define YELLOW_BACKGROUND "\033[43m"
# else
#  define YELLOW_BACKGROUND "\033[43m"
# endif

# ifndef BLUE_BACKGROUND
#  define BLUE_BACKGROUND "\033[44m"
# else
#  define BLUE_BACKGROUND "\033[44m"
# endif

# ifndef MAGENTA_BACKGROUND
#  define MAGENTA_BACKGROUND "\033[45m"
# else
#  define MAGENTA_BACKGROUND "\033[45m"
# endif

std::string	center(std::string input, int width = 120) { 
    return std::string((width - input.length()) / 2, ' ') + input;
}

int	main(void) {
	std::string	fighter("Kakarot");
	std::string	enemy("Vegetta");
	std::string	reader("answer");

	{
		std::cout << BLUE_TEXT << "=================================TEST 1===============================" << std::endl;
		std::cout << center("TESTING DIAMONDTRAP DEAFULT CONSTRUCTOR", 70) << std::endl << WHITE_TEXT;
		{
			DiamondTrap	a;
			(void)a;
		}
		std::cout << BLUE_TEXT << "=================================TEST 1===============================" << std::endl << WHITE_TEXT;
	}

	while (!std::cin.eof() && !reader.empty()) {
		std::cout << "Press Enter to continue ..." << std::endl;
		std::getline(std::cin, reader);
	}
	{
		std::cout << RED_TEXT << "=================================TEST 2===============================" << std::endl;
		std::cout << center("TESTING DIAMONDTRAP COPY CONSTRUCTOR", 70) << std::endl << WHITE_TEXT;
		{
			DiamondTrap	a;
			DiamondTrap	b(a);
			(void)a;
			(void)b;
		}
		std::cout << RED_TEXT << "=================================TEST 2===============================" << std::endl << WHITE_TEXT;
	}

	reader = "answer";
	while (!std::cin.eof() && !reader.empty()) {
		std::cout << "Press Enter to continue ..." << std::endl;
		std::getline(std::cin, reader);
	}

	{
		std::cout << YELLOW_TEXT << "=================================TEST 3===============================" << std::endl;
		std::cout << center("TESTING DIAMONDTRAP STRING CONSTRUCTOR", 70) << std::endl << WHITE_TEXT;
		{
			DiamondTrap	a(fighter);
			(void)a;
		}
		std::cout << YELLOW_TEXT << "=================================TEST 3===============================" << std::endl;
		std::cout << WHITE_TEXT;
	}

	reader = "answer";
	while (!std::cin.eof() && !reader.empty()) {
		std::cout << "Press Enter to continue ..." << std::endl;
		std::getline(std::cin, reader);
	}

	{
		std::cout << BLUE_TEXT << "=================================TEST 4===============================" << std::endl;
		std::cout << center("TESTING DIAMONDTRAP COPY ASSGINMENT", 70) << std::endl << WHITE_TEXT;
		{
			DiamondTrap	a(fighter);
			DiamondTrap	b;
			(void)a;

			b = a;
			(void)b;
		}
		std::cout << BLUE_TEXT << "=================================TEST 4===============================" << std::endl;
		std::cout << std::endl << WHITE_TEXT;
	}

	reader = "answer";
	while (!std::cin.eof() && !reader.empty()) {
		std::cout << "Press Enter to continue ..." << std::endl;
		std::getline(std::cin, reader);
	}

	{
		std::cout << MAGENTA_TEXT << "=================================TEST 5===============================" << std::endl;
		std::cout << center("TESTING DIAMONDTRAP MEMBER FUNCTIONS 0", 70) << std::endl << WHITE_TEXT;
		{
			DiamondTrap	a(fighter);
			
			a.attack(enemy);
			a.takeDamage(3);
			a.beRepaired(15);
			a.takeDamage(45);
			a.attack(enemy);
			a.beRepaired(5);
			a.guardGate();
			a.highFiveGuys();
			a.whoAmI();
		}
		std::cout << MAGENTA_TEXT << "=================================TEST 5===============================" << std::endl;
		std::cout << std::endl << WHITE_TEXT;
	}

	reader = "answer";
	while (!std::cin.eof() && !reader.empty()) {
		std::cout << "Press Enter to continue ..." << std::endl;
		std::getline(std::cin, reader);
	}

	{
		std::cout << RED_TEXT << "=================================TEST 6===============================" << std::endl;
		std::cout << center("TESTING DIAMONDTRAP MEMBER FUNCTIONS 1", 70) << std::endl << WHITE_TEXT;
		{
			DiamondTrap	a(fighter);
			
			a.attack(enemy);
			a.takeDamage(5);
			a.beRepaired(5);
			a.takeDamage(5);
			a.attack(enemy);
			a.beRepaired(5);
			for (int i = 0; i < 50; i++) {
				a.attack(enemy);
			}
			a.beRepaired(5);
			a.attack(enemy);
			a.guardGate();
			a.highFiveGuys();
			a.whoAmI();
		}
		std::cout << RED_TEXT << "=================================TEST 6===============================" << std::endl;
		std::cout << std::endl << WHITE_TEXT;
	}

	reader = "answer";
	while (!std::cin.eof() && !reader.empty()) {
		std::cout << "Press Enter to continue ..." << std::endl;
		std::getline(std::cin, reader);
	}

	{
		std::cout << GREEN_TEXT << "=================================TEST 7===============================" << std::endl;
		std::cout << center("TESTING DIAMONDTRAP MEMBER FUNCTIONS 2", 70) << std::endl << WHITE_TEXT;
		{
			DiamondTrap	a(fighter);
			
			for (int i = 0; i < 50; i++) {
				a.beRepaired(10);
			}
			a.attack(enemy);
			a.guardGate();
			a.highFiveGuys();
			a.whoAmI();
		}
		std::cout << GREEN_TEXT << "=================================TEST 7===============================" << std::endl;
		std::cout << std::endl << WHITE_TEXT;
	}
	return (0);
}
