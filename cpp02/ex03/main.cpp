/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:58:30 by discallow         #+#    #+#             */
/*   Updated: 2025/02/21 02:25:30 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(const Point& A, const Point& B, const Point& C) {
	return (Fixed(0.5f) * (A.getX() * (B.getY() - C.getY()) +
					B.getX() * (C.getY() - A.getY()) +
					C.getX() * (A.getY() - B.getY())));
}

bool isValidTriangle(const Point& A, const Point& B, const Point& C) {
	return (calculateArea(A, B, C) != Fixed(0));
}

bool isInsideTriangle(const Point& A, const Point& B, const Point& C, const Point& P) {
	Fixed areaABC = calculateArea(A, B, C);
	Fixed areaPBC = calculateArea(P, B, C);
	Fixed areaPCA = calculateArea(P, C, A);
	Fixed areaPAB = calculateArea(P, A, B);

    return (areaABC == (areaPBC + areaPCA + areaPAB));
}

int main(void) {
	Point A(0.0f, 0.0f);
	Point B(4.0f, 0.0f);
	Point C(2.0f, 3.0f);
	Point P(2.0f, 1.0f);

	if (isValidTriangle(A, B, C)) {
		if (isInsideTriangle(A, B, C, P)) {
			std::cout << "Point P is inside the triangle." << std::endl;
		} else {
			std::cout << "Point P is outside the triangle." << std::endl;
	}
	} else {
		std::cout << "The triangle is not valid." << std::endl;
	}
	return (0);
}
