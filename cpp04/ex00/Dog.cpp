/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/01 16:31:02 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	_type = "Dog";
	std::cout << BLUE << "Dog " << _type << " default constructor called!" << RESET << std::endl;
}

Dog::~Dog(void) {
	std::cout << BLUE << "Dog " << _type << " destructor constructor called!" << RESET << std::endl;	
}

Dog::Dog(const Dog& other): Animal(other) {
	_type = other._type;
	std::cout << YELLOW << "Dog " << _type << " copy constructor called!" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << GREEN << "Dog " << _type << " overload operator called!" << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Bark bark" << std::endl;
}