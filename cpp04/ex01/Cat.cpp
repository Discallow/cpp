/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/05 20:21:49 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	_type = "Cat";
	_brain = new Brain();
	std::cout << BLUE << "Cat " << _type << " default constructor called!" << RESET << std::endl;
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << BLUE << "Cat " << _type << " destructor constructor called!" << RESET << std::endl;	
}

Cat::Cat(const Cat& other): Animal(other) {
	this->_type = other._type;
	_brain = new Brain();
	std::cout << YELLOW << "Cat " << _type << " copy constructor called!" << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << GREEN << "Cat " << _type << " overload operator called!" << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Meow meow" << std::endl;
}

void	Cat::setIdea(std::string idea, size_t index) {
	_brain->setIdea(idea, index);
}

void	Cat::showIdeas(void) const {
	for (size_t i = 0; i < _brain)
}