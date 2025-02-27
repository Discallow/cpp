/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:19:57 by discallow         #+#    #+#             */
/*   Updated: 2025/02/26 19:08:17 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("unknown_clap_name"), ScavTrap(), FragTrap(), _name("unknown") {
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
	ClapTrap::_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_attackDamage = FragTrap::_attackDamage;
	std::cout << BLUE << "DiamondTrap " << _name << " default constructor called!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name") {
	_name = name;
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
	ClapTrap::_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap initialized with energy points: " << ClapTrap::_energyPoints << std::endl;
	std::cout << CYAN << "DiamondTrap " << _name << " constructor called!" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << BLUE << "DiamondTrap " << _name << " destroyed!" << RESET << std::endl;	
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		ClapTrap::_hitPoints = FragTrap::_hitPoints;
		ClapTrap::_energyPoints = ScavTrap::_energyPoints;
		ClapTrap::_attackDamage = FragTrap::_attackDamage;
		_name = other._name;
	}
	std::cout << GREEN << "DiamondTrap " << _name << " overload operator called!" << RESET << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other._name + "_clap_name"), 
	ScavTrap(other), FragTrap(other), _name(other._name) {
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
	ClapTrap::_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << _name << " copy constructor called!" << RESET << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	if (!_hitPoints) {
		std::cout << "DiamondTrap " << _name << " is dead, so it can't attack!" << std::endl;
		return ;
	}
	else if (!_energyPoints) {
		std::cout << "DiamondTrap " << _name << " doesn't have any energy available!" << std::endl;
		return ;
	}
	ScavTrap::attack(target);
	ClapTrap::_energyPoints--;	
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << RED << _name << RESET 
	<< " ClapTrap name: " << RED << _clap_name << RESET << std::endl;
}