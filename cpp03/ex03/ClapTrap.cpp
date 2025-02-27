/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:41:58 by discallow         #+#    #+#             */
/*   Updated: 2025/02/26 18:29:08 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _clap_name("unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << BLUE << "ClapTrap " << _clap_name << " default constructor called!" << RESET << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << BLUE << "ClapTrap " << _clap_name << " destroyed!" << RESET << std::endl;	
}

ClapTrap::ClapTrap(const std::string& name): _clap_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << CYAN << "ClapTrap " << _clap_name << " constructor called!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _clap_name(other._clap_name), _hitPoints(other._hitPoints), 
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage){
	std::cout << YELLOW << "ClapTrap " << other._clap_name << " copy constructor called!" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->_clap_name = other._clap_name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	std::cout << GREEN << "ClapTrap " << _clap_name << " overload operator called!" << RESET << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (!_hitPoints) {
		std::cout << "ClapTrap " << _clap_name << " is dead, so it can't attack!" << std::endl;
		return ;
	}
	else if (!_energyPoints) {
		std::cout << "ClapTrap " << _clap_name << " doesn't have any energy available!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _clap_name << " attacks " << target << ", causing " << RED
		<< _attackDamage << RESET << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints) {
		if (amount > _hitPoints)
			amount = _hitPoints;
		std::cout << _clap_name << " took " << RED << amount << RESET << " of damage!" << std::endl;
		_hitPoints -= amount;
	}
	else
		std::cout << _clap_name << " is already DEAD!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!_hitPoints) {
		std::cout << _clap_name << " is already DEAD!" << std::endl;
		return ;
	}
	else if (!_energyPoints) {
		std::cout << _clap_name << " doesn't have any energy available!" << std::endl;
		return ;
	}
	std::cout << _clap_name << " repaired " << RED << amount << RESET
		<< " hit points back! It has this energy points:" << RED << _energyPoints << RESET << std::endl;
	_energyPoints--;
	_hitPoints += amount;
}