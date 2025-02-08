/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:00:27 by discallow         #+#    #+#             */
/*   Updated: 2025/02/08 13:04:42 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	randomChump("Walker");
	Zombie	*newZm = newZombie("Walker2");
	newZm->announce();
	delete newZm;
	return (0);
}