/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:55:53 by discallow         #+#    #+#             */
/*   Updated: 2025/03/07 17:43:23 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
	
}

void	HumanB::setWeapon(Weapon &type) {
	_weapon = &type;
}

void	HumanB::attack(void) {
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
	std::cout << _name << " doesn't have any weapon to attack" << std::endl;
}