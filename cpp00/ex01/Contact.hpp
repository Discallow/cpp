/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:41:10 by discallow         #+#    #+#             */
/*   Updated: 2025/02/06 18:34:39 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include <cctype>
# include <cstdlib>
# include <iomanip>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define YELLOW		"\033[33m"
#define CAPACITY	8

class Contact
{
	public:
		std::string	getContactInfo(size_t type);
		std::string	&setContactInfo(size_t type);
		bool		setContact(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		bool		_checkWhiteSpaces(std::string str, size_t index);
		bool		_checkNumbers(std::string str, size_t index);
};

#endif