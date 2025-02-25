/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:10:44 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 21:12:11 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
	std::cout << "--- Creating ClapTrap ---" << std::endl;
	ClapTrap	clap("Clappy");
	clap.attack("target1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- Creating ScavTrap ---" << std::endl;
	ScavTrap	scav("Scavy");
	scav.attack("target2");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n--- Creating FragTrap ---" << std::endl;
	FragTrap	frag("Fraggy");
	frag.attack("target3");
	frag.takeDamage(30);
	frag.beRepaired(15);
	frag.highFiveGuys();

	std::cout << "\n--- Testing Copy Constructor & Assignment ---" << std::endl;
	FragTrap	fragCopy(frag);
	fragCopy.attack("target4");

	FragTrap	fragAssigned;
	fragAssigned = frag;
	fragAssigned.highFiveGuys();

	std::cout << "\n--- Destroying Objects ---" << std::endl;
	return (0);
}

