/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 05:45:58 by discallow         #+#    #+#             */
/*   Updated: 2025/02/19 16:11:19 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {
	
}

Point::~Point(void) {
	
}

Point::Point(float x, float y): _x(x), _y(y) {
	
}

Point::Point(const Point &other): _x(other._x), _y(other._y) {
	
}

Point& Point::operator=(const Point& other) {
	std::cout << "Assignment is not allowed!" << std::endl;
	return (*this);
}
