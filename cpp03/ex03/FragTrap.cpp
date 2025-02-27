/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:19:57 by discallow         #+#    #+#             */
/*   Updated: 2025/02/26 19:16:23 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << BLUE << "FragTrap " << _clap_name << " default constructor called!" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << CYAN << "FragTrap " << _clap_name << " constructor called!" << RESET << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << BLUE << "FragTrap " << _clap_name << " destroyed!" << RESET << std::endl;	
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << GREEN << "FragTrap " << _clap_name << " overload operator called!" << RESET << std::endl;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	
	std::cout << YELLOW << "FragTrap " << _clap_name << " copy constructor called!" << RESET << std::endl;
}

void FragTrap::highFiveGuys() {
	if (!_hitPoints)
		std::cout << RED << "FragTrap " << _clap_name << " is already dead!" << RESET << std::endl;
	else if (!_energyPoints)
		std::cout << RED << "FragTrap " << _clap_name << " doesn't have any energy available!" << RESET << std::endl;
	else
		std::cout << GRAY << "FragTrap " << _clap_name << " requests a high five!" << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (!_hitPoints) {
		std::cout << "FragTrap " << _clap_name << " is dead, so it can't attack!" << std::endl;
		return ;
	}
	else if (!_energyPoints) {
		std::cout << "FragTrap " << _clap_name << " doesn't have any energy available!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _clap_name << " attacks " << target << ", causing " << RED
		<< _attackDamage << RESET << " points of damage!" << std::endl;
	_energyPoints--;	
}