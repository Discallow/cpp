/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:58:31 by discallow         #+#    #+#             */
/*   Updated: 2025/02/08 14:25:40 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*Zm = zombieHorde(ZOMBIES, "Walker");
	for (int i = 0; i < ZOMBIES; i++)
		Zm[i].announce();
	delete[] Zm;
}