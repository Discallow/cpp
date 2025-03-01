/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/01 16:34:16 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	_type = "WrongCat";
	std::cout << BLUE << "WrongCat " << _type << " default constructor called!" << RESET << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << BLUE << "WrongCat " << _type << " destructor constructor called!" << RESET << std::endl;	
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
	std::cout << YELLOW << "WrongCat " << _type << " copy constructor called!" << RESET << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << GREEN << "WrongCat " << _type << " overload operator called!" << RESET << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Meow meow" << std::endl;
}