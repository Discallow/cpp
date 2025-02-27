/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:19:57 by discallow         #+#    #+#             */
/*   Updated: 2025/02/26 18:54:54 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << BLUE << "ScavTrap " << _clap_name << " default constructor called!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << CYAN << "ScavTrap " << _clap_name << " constructor called!" << RESET << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << BLUE << "ScavTrap " << _clap_name << " destroyed!" << RESET << std::endl;	
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << GREEN << "ScavTrap " << _clap_name << " overload operator called!" << RESET << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	std::cout << YELLOW << "ScavTrap " << _clap_name << " copy constructor called!" << RESET << std::endl;
}

void ScavTrap::guardGate() {
	if (_hitPoints && _energyPoints)
		std::cout << GRAY << "ScavTrap " << _clap_name << " is now in Gate Keeper mode!" << RESET << std::endl;
	else if (!_energyPoints)
		std::cout << "ScavTrap " << _clap_name << " doesn't have any energy available!" << std::endl;
	else
		std::cout << RED << "ScavTrap " << _clap_name << " is already dead!" << RESET << std::endl;	
}

void	ScavTrap::attack(const std::string& target) {
	if (!_hitPoints) {
		std::cout << "ScavTrap " << _clap_name << " is dead, so it can't attack!" << std::endl;
		return ;
	}
	else if (!_energyPoints) {
		std::cout << "ScavTrap " << _clap_name << " doesn't have any energy available!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _clap_name << " attacks " << target << ", causing " << RED
		<< _attackDamage << RESET << " points of damage!" << std::endl;
	_energyPoints--;	
}