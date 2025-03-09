/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:52:24 by discallow         #+#    #+#             */
/*   Updated: 2025/03/09 18:13:18 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter {
	private:
		AMateria*	_inv[4];
		AMateria**	_storedMateria;
		std::string	_name;
		int			_unnequipLen;
	public:
		Character(void);
		~Character(void);
		Character(const Character& other);
		Character(std::string& name);
		Character& operator=(const Character& other);
		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif
