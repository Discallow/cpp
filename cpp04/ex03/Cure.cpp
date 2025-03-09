/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:28:04 by discallow         #+#    #+#             */
/*   Updated: 2025/03/09 18:09:56 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) {
	_type = "cure";
}

Cure::~Cure(void) {
	
}

Cure::Cure(const Cure& other): AMateria(other) {
	
}

Cure& Cure::operator=(const Cure& other) {
	(void)other;
	return (*this);
}

AMateria*	Cure::clone(void) const {
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}