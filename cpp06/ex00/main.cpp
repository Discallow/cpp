/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:57:47 by discallow         #+#    #+#             */
/*   Updated: 2025/03/20 20:19:29 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << RED << "Wrong input. Usage: ./convert <literal>"
		<< RESET << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}