/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:19:57 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 20:22:54 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << BLUE << "FragTrap " << _name << " default constructor called!" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << CYAN << "FragTrap " << _name << " constructor called!" << RESET << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << BLUE << "FragTrap " << _name << " destroyed!" << RESET << std::endl;	
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << GREEN << "FragTrap " << _name << " overload operator called!" << RESET << std::endl;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	std::cout << YELLOW << "FragTrap " << _name << " copy constructor called!" << RESET << std::endl;
}

void FragTrap::highFiveGuys() {
	if (!_hitPoints)
		std::cout << RED << "FragTrap " << _name << " is already dead!" << RESET << std::endl;
	else if (!_energyPoints)
		std::cout << RED << "FragTrap " << _name << " doesn't have any energy available!" << RESET << std::endl;
	else
		std::cout << GRAY << "FragTrap " << _name << " requests a high five!" << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (!_hitPoints) {
		std::cout << "FragTrap " << _name << " is dead, so it can't attack!" << std::endl;
		return ;
	}
	else if (!_energyPoints) {
		std::cout << "FragTrap " << _name << " doesn't have any energy available!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << RED
		<< _attackDamage << RESET << " points of damage!" << std::endl;
	_energyPoints--;	
}