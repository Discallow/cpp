/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:30:29 by discallow         #+#    #+#             */
/*   Updated: 2025/02/11 10:14:49 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl	harl;
	if (ac != 2)
		return (std::cout << "Insert 2 arguments" << std::endl, 1);
	std::string	level = av[1];
	harl.complain(level);
	return (0);
}