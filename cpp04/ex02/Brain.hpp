/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:24:21 by discallow         #+#    #+#             */
/*   Updated: 2025/03/08 15:31:01 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
private:
	std::string	_ideas[100];
	size_t		_size;
public:
	Brain(void);
	~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	void		setIdea(std::string idea, size_t index);
	std::string	getIdea(size_t index) const;
	size_t		getSize(void) const;
};

#endif
