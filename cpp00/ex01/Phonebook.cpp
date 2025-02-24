/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:52:46 by discallow         #+#    #+#             */
/*   Updated: 2025/02/20 21:38:46 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

Phonebook::Phonebook(void): _index(0), _savedContacts(0) {
	
}

Phonebook::~Phonebook(void) {
	
}

size_t	Phonebook::getSavedContacts(void) const{
	return (this->_savedContacts);
}

Contact Phonebook::getContact(size_t _index) const {
	return (this->_contacts[_index]);
}

Contact &Phonebook::setContactIndex(void){
	size_t	i = this->_index;
	this->_index++;
	if (_savedContacts < CAPACITY)
		_savedContacts++;
	if (this->_index == CAPACITY){
		this->_index = 0;
	}
	return (this->_contacts[i]);
}