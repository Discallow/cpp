/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:57 by discallow         #+#    #+#             */
/*   Updated: 2025/03/01 16:31:07 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# ifndef RED
#  define RED	"\033[31m"
# endif
# ifndef GREEN
#  define GREEN	"\033[32m"
# endif
# ifndef BLUE
#  define BLUE	"\033[34m"
# endif
# ifndef WHITE
#  define WHITE	"\033[37m"
# endif
# ifndef BLACK
#  define BLACK	"\033[30m"
# endif
# ifndef YELLOW
#  define YELLOW	"\033[33m"
# endif
# ifndef CYAN
#  define CYAN	"\033[36m"
# endif
# ifndef GRAY
#  define GRAY	"\033[90m"
# endif
# ifndef RESET
#  define RESET	"\033[0m"
# endif

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		void 	makeSound(void) const;
		std::string		getType(void) const;
		void			setType(const std::string& name);
};

#endif