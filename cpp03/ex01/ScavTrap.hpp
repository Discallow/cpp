/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:04:43 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 00:51:57 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(const std::string& name);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap& other);
		ScavTrap(const ScavTrap& other);
		void	guardGate();
		void	attack(const std::string& target);
};

#endif
