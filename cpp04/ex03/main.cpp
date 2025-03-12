/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:48:40 by arabelo-          #+#    #+#             */
/*   Updated: 2025/03/12 11:53:34 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void    testMateriaSource(void) {
    std::cout << "\n===== TESTING MATERIA SOURCE =====\n";
    IMateriaSource* src = new MateriaSource();
    std::cout << "Learning Ice Materia...\n";
    src->learnMateria(new Ice());

    std::cout << "Learning Cure Materia...\n";
    src->learnMateria(new Cure());

    std::cout << "Trying to create an unknown Materia (\"fire\")...\n";
    AMateria* tmp = src->createMateria("fire");
    if (!tmp)
        std::cout << "Fire Materia not found, as expected.\n";
    std::cout << "Trying to learn more than 4 Materias...\n";
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());

    delete src;
}

void    testCharacterUsage(void) {
    std::cout << "\n===== TESTING CHARACTER USAGE =====\n";

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    std::cout << "Using Materia slots 0 and 1 on Bob...\n";
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "Unequipping Materia at slot 0...\n";
    me->unequip(0);

    std::cout << "Trying to use an unequipped slot...\n";
    me->use(0, *bob);

    delete bob;
    delete me;
    delete src;
}

void testCopyConstructor(void) {
    std::cout << "\n===== TESTING COPY CONSTRUCTOR =====\n";

    Character original("Original");

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    original.equip(ice);
    original.equip(cure);

    std::cout << "Creating a copy of 'original'...\n";
    Character copy(original);

    std::cout << "Original uses Materia on itself...\n";
    original.use(0, original);
    original.use(1, original);

    std::cout << "Copy uses Materia on itself...\n";
    copy.use(0, copy);
    copy.use(1, copy);

    std::cout << "Deleting original and copy...\n";
}

void testAssignmentOperator() {
    std::cout << "\n===== TESTING ASSIGNMENT OPERATOR =====\n";

    Character a("A");
    Character b("B");

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    a.equip(ice);
    a.equip(cure);

    std::cout << "Assigning A to B...\n";
    b = a;

    std::cout << "A uses Materia on itself...\n";
    a.use(0, a);
    a.use(1, a);

    std::cout << "B uses Materia on itself...\n";
    b.use(0, b);
    b.use(1, b);

    std::cout << "Deleting A and B...\n";
}

int main(void) {
    testMateriaSource();
    testCharacterUsage();
    testCopyConstructor();
    testAssignmentOperator();

    std::cout << "\n===== ALL TESTS COMPLETED =====\n";
    return (0);
}

