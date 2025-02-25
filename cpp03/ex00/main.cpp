/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:19:38 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 19:57:18 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap	clap0;
	ClapTrap	clap1("CL4P-TP");
	ClapTrap	clap2("FR4G-TP");
	
	clap1.attack("Bandit");
	clap2.attack("Bandit2");

	clap1.takeDamage(5);
	clap1.takeDamage(3);
	clap1.takeDamage(4);

	clap2.beRepaired(4);
	clap1.beRepaired(3);

	for (int i = 0; i < 10; i++)
		clap2.attack("Dummy Target");

	// Testing copy constructor
	ClapTrap	clap3(clap2);
	clap3.attack("Another Dummy");

	// Testing assignment operator
	ClapTrap	clap4("Master Dummy");
	clap3 = clap4;
	clap3.attack("Final Dummy");

	return (0);
}