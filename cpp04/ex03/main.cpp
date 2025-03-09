/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:48:40 by arabelo-          #+#    #+#             */
/*   Updated: 2025/03/09 17:59:04 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {
    // Create a character and equip Materia

	std::string alice = "Alice";
    Character c1(alice);
    
    // Create Materia objects
    AMateria* cure = new Cure();
    AMateria* ice = new Ice();
    
    // Equip Materia to the character
    std::cout << "Equipping Materia..." << std::endl;
    c1.equip(cure); // Equip Cure
    c1.equip(ice);  // Equip ice
    
    // Use equipped Materia
    std::cout << "\nUsing Materia..." << std::endl;
    c1.use(0, c1);  // Use Cure (slot 0)
    c1.use(1, c1);  // Use ice (slot 1)
    
    // Unequip a Materia
    std::cout << "\nUnequipping Materia..." << std::endl;
    c1.unequip(0);  // Unequip Cure
    
    // Try to use the unequipped Materia
    std::cout << "\nTrying to use unequipped Materia..." << std::endl;
    c1.use(0, c1);  // Should give an error ("There's nothing to use in that slot!")
    
    // Clean up (will happen automatically in the destructor)
    std::cout << "\nDeleting Character (destructor will free memory)..." << std::endl;
    
    return 0;
}

