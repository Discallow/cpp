/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 03:49:21 by discallow         #+#    #+#             */
/*   Updated: 2025/02/19 16:24:23 by discallow        ###   ########.fr       */
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
		Fixed& operator++();
		Fixed  operator++(int);
		Fixed& operator--();
		Fixed  operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


Fixed	operator+(const Fixed& a, const Fixed& b);
Fixed	operator-(const Fixed& a, const Fixed& b);
Fixed	operator*(const Fixed& a, const Fixed& b);
Fixed	operator/(const Fixed& a, const Fixed& b);
bool	operator>(const Fixed& a, const Fixed& b);
bool	operator<(const Fixed& a, const Fixed& b);
bool	operator>=(const Fixed& a, const Fixed& b);
bool	operator<=(const Fixed& a, const Fixed& b);
bool	operator==(const Fixed& a, const Fixed& b);
bool	operator!=(const Fixed& a, const Fixed& b);

#endif