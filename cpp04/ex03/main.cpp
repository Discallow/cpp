/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:48:40 by arabelo-          #+#    #+#             */
/*   Updated: 2025/03/10 10:29:02 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {
    ICharacter *c1 = new Character("Alice");
/*     AMateria* cure = new Cure();
    AMateria* ice = new Ice();

    std::cout << "Equipping Materia..." << std::endl;
    c1->equip(cure);
    c1->equip(ice);

    std::cout << "\nUsing Materia..." << std::endl;
    c1->use(0, *c1);
    c1->use(1, *c1);

    std::cout << "\nUnequipping Materia..." << std::endl;
    c1->unequip(0);

    std::cout << "\nTrying to use unequipped Materia..." << std::endl;
    c1->use(0, *c1); */

    delete c1;
    return (0);
}

