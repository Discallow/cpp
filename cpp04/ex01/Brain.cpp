/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/08 15:48:50 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void): _size(0) {
	std::cout << BLUE << "Brain default constructor called!" << RESET << std::endl;
}

Brain::~Brain(void) {
	std::cout << BLUE << "Brain destructor called!" << RESET << std::endl;	
}

Brain::Brain(const Brain& other){
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << YELLOW << "Brain copy constructor called!" << RESET << std::endl;
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout << GREEN << "Brain overload operator called!" << RESET << std::endl;
	return (*this);
}

void	Brain::setIdea(std::string idea, size_t index) {
	if (index < 100) {
		if (_ideas[index].empty())
			this->_size++;
		_ideas[index] = idea;
	}
}

size_t	Brain::getSize(void) const {
	size_t count = 0;
	for (size_t i = 0; i < 100; i++) {
		if (!_ideas[i].empty())
			count++;
    }
	return (count);
}

std::string	Brain::getIdea(size_t index) const {
	return (_ideas[index]);
}
