/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:52:15 by discallow         #+#    #+#             */
/*   Updated: 2025/02/20 21:38:26 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class	Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
		Contact	&setContactIndex(void);
		Contact	getContact(size_t index) const;
		size_t	getSavedContacts(void) const;
	private:
		Contact _contacts[8];
		size_t	_index;
		size_t	_savedContacts;
};
#endif