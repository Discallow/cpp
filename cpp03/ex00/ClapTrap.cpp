/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:41:58 by discallow         #+#    #+#             */
/*   Updated: 2025/02/24 00:43:39 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << BLUE << "Default constructor called!" << RESET << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << BLUE << "Default destructor called!" << RESET << std::endl;	
}

ClapTrap::ClapTrap(std::string& name): _name(name) {
	std::cout << CYAN << "Constructor called!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoints(other._hitPoints), 
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage){
	std::cout << YELLOW << "Copy constructor called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	std::cout << GREEN << "Overload operator called!" << RESET << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (_energyPoints && _hitPoints) {
		std::cout << "ClapTrap " << _name << " attacks" << target << ", causing " << RED
			<< _attackDamage << RESET << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints) {
		std::cout << _name << " took " << RED << amount << RESET << "of damage!" << std::endl;
		_hitPoints--;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints && _hitPoints) {
		std::cout << _name << " repaired " << RED << amount << RESET
			" hit points back!" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
	}
}