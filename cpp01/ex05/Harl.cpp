/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:55:27 by discallow         #+#    #+#             */
/*   Updated: 2025/02/11 09:14:14 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put ";
	std::cout << "enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for";
	std::cout << " years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::_notFound(void) {
	std::cerr << "Complain not Found" << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functionPointer[])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error, &Harl::_notFound};
	int	i = 0;
	while (i < 4 && level != options[i])
		i++;
	(this->*functionPointer[i])();
}