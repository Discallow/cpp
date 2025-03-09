/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:22:33 by discallow         #+#    #+#             */
/*   Updated: 2025/03/09 14:48:02 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure(void);
		~Cure(void);
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif