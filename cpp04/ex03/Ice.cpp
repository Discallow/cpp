/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:28:04 by discallow         #+#    #+#             */
/*   Updated: 2025/03/09 18:08:30 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) {
	_type = "ice";
}

Ice::~Ice(void) {
	
}

Ice::Ice(const Ice& other): AMateria(other) {
}

Ice& Ice::operator=(const Ice& other) {
	(void)other;
	return (*this);
}

AMateria*	Ice::clone(void) const {
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}