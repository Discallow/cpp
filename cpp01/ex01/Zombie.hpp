/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:54:37 by discallow         #+#    #+#             */
/*   Updated: 2025/02/08 14:25:12 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define ZOMBIES	8

class Zombie
{
private:
	std::string	_name;
public:
	void	announce(void);
	void	setName(const std::string &inputName);
	~Zombie();
};

Zombie	*zombieHorde (int N, std::string name);
#endif