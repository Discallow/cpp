/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:48:40 by arabelo-          #+#    #+#             */
/*   Updated: 2025/03/08 16:03:46 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int numAnimals = 4;
	Animal* animals[numAnimals];

	for (int i = 0; i < numAnimals; i++) {
		if (i < numAnimals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::string ideas[5] = {
		"I want to play!",
		"I am hungry!",
		"Where is my human?",
		"Let's take a nap.",
		"I need to chase something!"
	};
	for (int i = 0; i < numAnimals; i++) {
		for (size_t j = 0; j < 5; j++) {
			animals[i]->setIdea(ideas[j], j);
		}
	}
	std::cout << "\n==== Printing All Ideas ====\n";
	for (int i = 0; i < numAnimals; i++) {
		std::cout << animals[i]->getType() << ":\n";
		animals[i]->showIdeas();
		std::cout << std::endl;
	}
	for (int i = 0; i < numAnimals; i++) {
		delete animals[i];
	}
    return (0);
}
