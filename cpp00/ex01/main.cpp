/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:52:34 by discallow         #+#    #+#             */
/*   Updated: 2025/02/07 17:11:11 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

static void	selectSpecificContact(Phonebook *phonebook) {
	std::string	input;
	std::string	str;
	int			index;
	Contact		contact;
	
	std::cout << YELLOW << "Select one contact to get all the details:" << RESET;
	std::getline(std::cin, input);
	if (input.length() != 1 || input.at(0) < '0' || input.at(0) > '7') {
		std::cout << RED << "Invalid contact" << RESET << std::endl;
		return ;
	}
	index = input.at(0) - 48;
	contact = phonebook->getContact(index);
	std::cout << RED << "First name: " << RESET;
	std::cout << contact.getContactInfo(0) << std::endl;
	std::cout << RED << "Last name: " << RESET;
	std::cout << contact.getContactInfo(1) << std::endl;
	std::cout << RED << "Nickname: " << RESET;
	std::cout << contact.getContactInfo(2) << std::endl;
	std::cout << RED << "Phone number: " << RESET;
	std::cout << contact.getContactInfo(3) << std::endl;
	std::cout << RED << "Darkest secret: " << RESET;
	std::cout << contact.getContactInfo(4) << std::endl;
}

static void	drawLine(void) {
	std::cout << " ";
	for (int i = 0; i < 43; i++)
		std::cout << "_";
}

static std::string checkStringSize(std::string str) {
	std::string	str_trimmed;
	
	if (str.length() <= 10)
		return (str);
	str_trimmed = str.substr(0, 9);
	str_trimmed.push_back('.');
	return (str_trimmed);
}

static void	showSavedContacts(Phonebook *phonebook) {
	std::string	str;
	Contact		contact;
	size_t		savedContacts;

	savedContacts = phonebook->getSavedContacts();
	
	for (size_t i = 0; i < savedContacts; i++){
		contact = phonebook->getContact(i);
		std::cout << "|" << std::setw(10) << i << "|";
		for (size_t j = 0; j < 3; j++) {
			str = contact.getContactInfo(j);
			std::cout << std::setw(10) << checkStringSize(str) << "|";
		}	
		std::cout << std::endl;
	}
	drawLine();
	std::cout << std::endl;
}

static void	searchContact(Phonebook *phonebook) {
	drawLine();
	std::cout << std::endl;
	std::cout << "|" << RED << std::setw(10) << "Index" << RESET << "|" << RED << std::setw(10) << "First Name" << RESET 
	<< "|" << RED << std::setw(10) << "Last Name" << RESET << "|" << RED << std::setw(10) << "Nickname" << RESET 
	<< "|" << std::endl;
	showSavedContacts(phonebook);
	selectSpecificContact(phonebook);
	sleep (2);
}

static bool	addContact(Phonebook *phonebook) {
	Contact &contact = phonebook->setContactIndex();
	if (!contact.setContact())
		return (false);
	return (true);
}

int	main(void){
	Phonebook 	phonebook;
	std::string	input;

	while (1)
	{
		system("clear");
		std::cout << YELLOW << "SELECT AN OPTION" << RESET << std::endl;
		std::cout << YELLOW << "ADD | SEARCH | EXIT" << RESET << std::endl;
		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD"){
			if (!addContact(&phonebook))
				break ;
		}
		else if (input == "SEARCH")
			searchContact(&phonebook);
		else if (input == "EXIT")
			break ;
		sleep(1);
	}
	return (0);
}