/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/01 16:31:26 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") {
	std::cout << BLUE << "WrongAnimal " << _type << " default constructor called!" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << BLUE << "WrongAnimal " << _type << " destructor constructor called!" << RESET << std::endl;	
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): _type(other._type) {
	std::cout << YELLOW << "WrongAnimal " << _type << " copy constructor called!" << RESET << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << GREEN << "WrongAnimal " << _type << " overload operator called!" << RESET << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::setType(const std::string& name) {
	_type = name;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "??????" << std::endl;
}