/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:04:51 by discallow         #+#    #+#             */
/*   Updated: 2025/02/11 09:09:21 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl	harl;
	std::cout << "Testing DEBUG" << std::endl;
	harl.complain("DEBUG");
	std::cout << "--------------" << std::endl;
	std::cout << "Testing INFO" << std::endl;
	harl.complain("INFO");
	std::cout << "--------------" << std::endl;
	std::cout << "Testing WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "--------------" << std::endl;
	std::cout << "Testing ERROR" << std::endl;
	harl.complain("ERROR");
	std::cout << "--------------" << std::endl;
	std::cout << "Testing invalid complain" << std::endl;
	harl.complain("INVALID");
	std::cout << "--------------" << std::endl;
	return (0);
}