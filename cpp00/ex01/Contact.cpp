/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:52:22 by discallow         #+#    #+#             */
/*   Updated: 2025/02/06 18:57:24 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	&Contact::setContactInfo(size_t type) {
	switch (type)
	{
		case (0):
			std::cout << RED << "First name: " << RESET;
			return (this->_firstName);
		case (1):
			std::cout << RED << "Last name: " << RESET;
			return (this->_lastName);
		case (2):
			std::cout << RED << "Nickname: " << RESET;
			return (this->_nickName);
		case (3):
			std::cout << RED << "Phonenumber: " << RESET;
			return (this->_phoneNumber);
		case (4):
			std::cout << RED << "Darkest secret: " << RESET;
			return (this->_darkestSecret);
		default:
			return (this->_firstName);
	}
}

std::string	Contact::getContactInfo(size_t type) {
	switch (type)
	{
		case (0):
			return (this->_firstName);
		case (1):
			return (this->_lastName);
		case (2):
			return (this->_nickName);
		case (3):
			return (this->_phoneNumber);
		case (4):
			return (this->_darkestSecret);
		default:
			return (this->_firstName);
	}
}

bool	Contact::setContact() {
	std::string	input;

	for (size_t i = 0; i < 5; i++)
	{
		std::string &temp = this->setContactInfo(i);
		while (!std::getline(std::cin, input) || (!_checkNumbers(input, i)) 
				|| !_checkWhiteSpaces(input, i) || input.empty())
		{
			if (std::cin.eof())
				return (false);
			std::cerr << "Invalid input!" << std::endl;
			sleep(1);
			system("clear");
			setContactInfo(i);
		}
		temp = input;
	}
	return (true);
}

bool	Contact::_checkNumbers(std::string str, size_t index) {
	bool	onlyNumbers = true;
	
	if (index == 3) {

		for (size_t i = 0; i < str.length(); i++) {
			if (!std::isdigit(str[i])) {
				onlyNumbers = false;
				break ;		
			}
		}
		if (!onlyNumbers)
			return (false);
	}
	else {
		for (size_t j = 0; j < str.length(); j++)
			if (std::isdigit(str[j]))
				return (false);		
	}
	return (true);
}

bool	Contact::_checkWhiteSpaces(std::string str, size_t index) {
	bool	onlySpaces = true;
	if (index == 2 || index == 4) {
		for (size_t i = 0; i < str.length(); i++) {
			if (!std::isspace(str[i])) {
				onlySpaces = false;
				break ;
			}
		}
		if (onlySpaces)
			return (false);
	}
	else {
		for (size_t j = 0; j < str.length(); j++) {
			if (std::isspace(str[j]) && index != 4)
				return (false);			
		}	
	}
	return (true);
}