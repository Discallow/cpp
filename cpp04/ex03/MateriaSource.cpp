/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:17:26 by discallow         #+#    #+#             */
/*   Updated: 2025/03/14 15:05:14 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		_storedMateria[i] = NULL;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (_storedMateria[i]) {
			delete _storedMateria[i];	
			_storedMateria[i] = NULL;			
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._storedMateria[i])
			this->_storedMateria[i] = other._storedMateria[i]->clone();
		else
			this->_storedMateria[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (other._storedMateria[i]) {
				delete _storedMateria[i];
				this->_storedMateria[i] = other._storedMateria[i]->clone();
			}
			else
				this->_storedMateria[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	size_t i = 0;
	while (i < 4 && _storedMateria[i])
		i++;
	if (i < 4)
		_storedMateria[i] = m->clone();
	else
		std::cout << "The inventory is full, you can't learn more materia!" << std::endl;

}

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (_storedMateria[i] && type == _storedMateria[i]->getType())
			return (_storedMateria[i]->clone());		
	}
	std::cout << "You cannot create a materia of type " << type << std::endl;
	return (NULL);
}