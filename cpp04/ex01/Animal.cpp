/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/05 20:11:22 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal") {
	std::cout << BLUE << "Animal " << _type << " default constructor called!" << RESET << std::endl;
}

Animal::~Animal(void) {
	std::cout << BLUE << "Animal " << _type << " destructor constructor called!" << RESET << std::endl;	
}

Animal::Animal(const Animal& other): _type(other._type) {
	std::cout << YELLOW << "Animal " << _type << " copy constructor called!" << RESET << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << GREEN << "Animal " << _type << " overload operator called!" << RESET << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::setType(const std::string& name) {
	_type = name;
}

void	Animal::makeSound(void) const {
	std::cout << "Grrrrr..." << std::endl;
}

void	Animal::setIdea(std::string idea, size_t index) {
	(void)idea;
	(void)index;
}

void	Animal::showIdeas(void) const {
	
}