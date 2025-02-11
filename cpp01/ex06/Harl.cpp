/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:55:27 by discallow         #+#    #+#             */
/*   Updated: 2025/02/11 10:33:26 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::_info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put ";
	std::cout << "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for";
	std::cout << " years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::_error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level) {
	int	i = 0;
	std::string	options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && level != options[i])
		i++;
	switch (i)
	{
		case 0:
			this->_debug();
			// Fall through
		case 1:
			this->_info();
			// Fall through
		case 2:
			this->_warning();
			// Fall through
		case 3:
			this->_error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
			break ;
	}
}