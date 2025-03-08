/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/08 15:54:29 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	_type = "Dog";
	_brain = new Brain();
	std::cout << BLUE << "Dog default constructor called!" << RESET << std::endl;
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << BLUE << "Dog destructor called!" << RESET << std::endl;	
}

Dog::Dog(const Dog& other): Animal(other) {
	this->_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << YELLOW << "Dog copy constructor called!" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << GREEN << "Dog overload operator called!" << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Bark bark" << std::endl;
}

void	Dog::setIdea(std::string idea, size_t index) {
	_brain->setIdea(idea, index);
}

void	Dog::showIdeas(void) const {
	std::cout << "Dog ideas:" << std::endl;
	for (size_t i = 0; i < _brain->getSize(); i++)
		std::cout << _brain->getIdea(i) << std::endl;
}