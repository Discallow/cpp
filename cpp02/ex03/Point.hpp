/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:38:58 by discallow         #+#    #+#             */
/*   Updated: 2025/02/21 02:16:46 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point(void);
		~Point(void);
		Point(float x, float y);
		Point(const Point &other);
		Point&	operator=(const Point &other);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif