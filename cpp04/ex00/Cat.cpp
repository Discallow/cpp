/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/08 15:52:12 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	_type = "Cat";
	std::cout << BLUE << "Cat default constructor called!" << RESET << std::endl;
}

Cat::~Cat(void) {
	std::cout << BLUE << "Cat destructor called!" << RESET << std::endl;	
}

Cat::Cat(const Cat& other): Animal(other) {
	std::cout << YELLOW << "Cat copy constructor called!" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << GREEN << "Cat overload operator called!" << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Meow meow" << std::endl;
}