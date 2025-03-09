/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:45 by discallow         #+#    #+#             */
/*   Updated: 2025/03/09 18:04:01 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _storedMateria(NULL), _unnequipLen(0){
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::~Character() {
    for (int i = 0; i < _unnequipLen; i++) {
        delete _storedMateria[i];  // Free all stored Materia
    }
    delete[] _storedMateria;  // Free the array itself
}

Character::Character(std::string& name): _name(name), _storedMateria(NULL), _unnequipLen(0) {
	for (int i = 0; i < 4; i++)
		_inv[i] = NULL;
}

Character::Character(const Character& other): _name(other._name), _storedMateria(NULL), _unnequipLen(0) {
	for (int i = 0; i < 4; i++) {
		if (other._inv[i])
			this->_inv[i] = other._inv[i]->clone();
		else
			this->_inv[i] = NULL;
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_storedMateria = other._storedMateria;
		this->_unnequipLen = other._unnequipLen;
		for (int i = 0; i < 4; i++) {
			if (other._inv[i])
				this->_inv[i] = other._inv[i]->clone();
			else
				this->_inv[i] = NULL;
		}
	}
	return (*this);
}

std::string const& Character::getName() const{
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	int	i;

	for (i = 0; i < 4; i++)
		if (!_inv[i])
			break ;
	if (i < 4) {
		_inv[i] = m;
		for (int i = 0; i < _unnequipLen; i++)
			if (_storedMateria[i] == m) {
				_storedMateria[i] = nullptr;
				break ;
			}
	}
	else
		std::cout << "The inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || !_inv[idx])
		return ;
	AMateria** newStorage = new AMateria*[_unnequipLen + 1];

	for (int i = 0; i < _unnequipLen; i++)
		newStorage[i] = _storedMateria[i];
	newStorage[_unnequipLen] = _inv[idx];
	delete[] _storedMateria;
	_storedMateria = newStorage;
	_unnequipLen++;
	_inv[idx] = nullptr;
}


void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;
	if (!_inv[idx]) {
		std::cout << "There's nothing to use in that slot!" << std::endl;
		return ;
	}
	_inv[idx]->use(target);
}