/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:03:47 by discallow         #+#    #+#             */
/*   Updated: 2025/03/11 09:39:41 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
	
}

AMateria::AMateria(const std::string& type): _type(type) {
	
}

AMateria::~AMateria(void) {

}

AMateria::AMateria(const AMateria& other): _type(other._type) {
	
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}

std::string	const& AMateria::getType(void) const {
	return (_type);
}