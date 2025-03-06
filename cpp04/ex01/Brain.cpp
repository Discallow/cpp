/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:31:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/05 20:19:54 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void): _size(0) {
	std::cout << BLUE << "Brain default constructor called!" << RESET << std::endl;
}

Brain::~Brain(void) {
	std::cout << BLUE << "Brain destructor constructor called!" << RESET << std::endl;	
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
	_ideas[index] = idea;
	_size++;
}