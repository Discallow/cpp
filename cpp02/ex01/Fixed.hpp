/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:04:05 by discallow         #+#    #+#             */
/*   Updated: 2025/02/15 04:34:10 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		static const int 	_fracBits = 8;
		int					_fixedPointNum;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream& out, const Fixed& fixed);

#endif