/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:48:40 by arabelo-          #+#    #+#             */
/*   Updated: 2025/03/05 16:58:16 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int	main(void) {
	{
		Animal	a;
		Cat		b;
		Dog		c;

		std::cout << std::endl << std::endl;

		a.makeSound();

		b.makeSound();

		c.makeSound();

		std::cout << std::endl << std::endl;
	}
	{
		std::cout << std::endl << std::endl;

		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << std::endl << std::endl;
		delete meta;
		delete j;
		delete i;
		std::cout << std::endl << std::endl;
	}
	return (0);
}