/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:22:33 by discallow         #+#    #+#             */
/*   Updated: 2025/03/08 23:40:14 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif