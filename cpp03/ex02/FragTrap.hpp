/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:04:43 by discallow         #+#    #+#             */
/*   Updated: 2025/02/25 20:19:43 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string& name);
		~FragTrap();
		FragTrap&	operator=(const FragTrap& other);
		FragTrap(const FragTrap& other);
		void	highFiveGuys(void);
		void	attack(const std::string& target);
};

#endif
