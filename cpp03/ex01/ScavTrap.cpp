/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:19:57 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 01:27:25 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << BLUE << "ScavTrap " << _name << " default constructor called!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << CYAN << "ScavTrap " << _name << " constructor called!" << RESET << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << BLUE << "ScavTrap " << _name << " destroyed!" << RESET << std::endl;	
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << GREEN << "ScavTrap " << _name << " overload operator called!" << RESET << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	std::cout << YELLOW << "ScavTrap " << _name << " copy constructor called!" << RESET << std::endl;
}

void ScavTrap::guardGate() {
	if (_hitPoints)
		std::cout << GRAY << "ScavTrap " << _name << " is now in Gate Keeper mode!" << RESET << std::endl;
	else
		std::cout << RED << "ScavTrap " << _name << " is already dead!" << RESET << std::endl;	
}

void	ScavTrap::attack(const std::string& target) {
	if (!_hitPoints) {
		std::cout << "ScavTrap " << _name << " is dead, so it can't attack!" << std::endl;
		return ;
	}
	else if (!_energyPoints) {
		std::cout << "ScavTrap " << _name << " doesn't have any energy available!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << RED
		<< _attackDamage << RESET << " points of damage!" << std::endl;
	_energyPoints--;	
}