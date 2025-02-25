/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:10:44 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 01:12:16 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"  // Include the header file for ScavTrap

int main() {
    // Test ClapTrap
    std::cout << "Testing ClapTrap:" << std::endl;
    ClapTrap clap1("Clap1");
    clap1.attack("Target1");
    
    clap1.takeDamage(10);
    clap1.attack("Target2");
    
    clap1.beRepaired(5);
    
    std::cout << std::endl;

    // Test ScavTrap
    std::cout << "Testing ScavTrap:" << std::endl;
    ScavTrap scav1("Scav1");
    scav1.attack("Target3");

    scav1.takeDamage(30);
    scav1.guardGate(); // Check guard gate mode
    scav1.attack("Target4");
    
    scav1.beRepaired(15);
    scav1.guardGate(); // Check guard gate mode again
    scav1.attack("Target5");
    

    // Test copy constructor and assignment operator
    std::cout << "Testing copy constructor and assignment operator:" << std::endl;
    ScavTrap scav2 = scav1; // Copy constructor
    scav2.attack("Target6");

    ScavTrap scav3("Scav3");
    scav3 = scav1; // Assignment operator
    scav3.attack("Target7");


    // Create multiple ScavTrap instances
    std::cout << "Creating multiple ScavTrap instances:" << std::endl;
    ScavTrap scav4; // Default constructor
    scav4.attack("Target8");

    ScavTrap scav5; // Another instance
    scav5.attack("Target9");
    return 0;
}
