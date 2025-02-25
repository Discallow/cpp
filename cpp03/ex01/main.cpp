/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:10:44 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 21:09:20 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	std::cout << "Testing ClapTrap:" << std::endl;
	ClapTrap	clap0;
	ClapTrap	clap1("Clap1");

	clap1.attack("Target1");
	clap1.takeDamage(10);
	clap1.attack("Target2");
	clap1.beRepaired(5);

	std::cout << "Testing ScavTrap:" << std::endl;
	ScavTrap	scav1("Scav1");

	scav1.attack("Target3");
	scav1.takeDamage(30);
	scav1.guardGate();
	scav1.attack("Target4");
	scav1.beRepaired(15);
	scav1.guardGate();
	scav1.attack("Target5");

	std::cout << "Testing copy constructor and assignment operator:" << std::endl;
	ScavTrap	scav2 = scav1;
	scav2.attack("Target6");

	ScavTrap scav3("Scav3");
	scav3 = scav1;
	scav3.attack("Target7");

	ScavTrap	scav4;
	scav4.attack("Target8");

	ScavTrap	scav5;
	scav5.attack("Target9");
	return (0);
}
