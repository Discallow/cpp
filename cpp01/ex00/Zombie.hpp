/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:32:53 by discallow         #+#    #+#             */
/*   Updated: 2025/02/08 13:07:02 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>


class Zombie
{
	public:
		Zombie (const std::string &inputName);
		~Zombie (void);
		void	announce(void);
	private:
		std::string	_name;
};

Zombie	*newZombie (std::string name);
void	randomChump (std::string name);

#endif