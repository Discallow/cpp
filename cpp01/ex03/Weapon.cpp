/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:58:51 by discallow         #+#    #+#             */
/*   Updated: 2025/02/08 17:10:56 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon): _weaponType(weapon) {
	
}

const std::string&	Weapon::getType(void) {
	return (_weaponType);
}

void	Weapon::setType(std::string newWeapon) {
	_weaponType = newWeapon;
}