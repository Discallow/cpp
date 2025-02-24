/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:58:30 by discallow         #+#    #+#             */
/*   Updated: 2025/02/24 01:49:47 by discallow        ###   ########.fr       */
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
	
    return (areaABC == (areaPBC + areaPCA + areaPAB)
		&& ((areaPBC > Fixed(0) && areaPCA > Fixed(0) && areaPAB > Fixed(0))
		|| (areaPBC < Fixed(0) && areaPCA < Fixed(0) && areaPAB < Fixed(0))));
}

void testPoint(const Point& A, const Point& B, const Point& C, const Point& P) {
	std::cout << "Triangle: (" << A.getX() << "," << A.getY() << "), ("
			<< B.getX() << "," << B.getY() << "), ("
			<< C.getX() << "," << C.getY() << ") | Testing P("
			<< P.getX() << "," << P.getY() << "): ";

	if (!isValidTriangle(A, B, C)) {
		std::cout << "❌ Invalid Triangle\n";
	} else if (isInsideTriangle(A, B, C, P)) {
		std::cout << "✅ Inside Triangle\n";
	} else {
		std::cout << "❌ Outside Triangle\n";
	}
}

int main() {
	
	// ✅ Valid Triangles
	testPoint(Point(0.0f, 0.0f), Point(4.0f, 0.0f), Point(2.0f, 3.0f), Point(2.0f, 1.0f));
	testPoint(Point(0.0f, 0.0f), Point(4.0f, 0.0f), Point(2.0f, 3.0f), Point(4.0f, 0.0f));
	testPoint(Point(0.0f, 0.0f), Point(4.0f, 0.0f), Point(2.0f, 3.0f), Point(5.0f, 5.0f));
	testPoint(Point(-2.0f, -1.0f), Point(3.0f, 4.0f), Point(1.0f, -3.0f), Point(0.0f, 0.0f)); 
	testPoint(Point(0.0f, 0.0f), Point(5.0f, 0.0f), Point(2.5f, 5.0f), Point(2.5f, 2.5f));
	testPoint(Point(1.0f, 1.0f), Point(4.0f, 1.0f), Point(2.5f, 4.0f), Point(3.0f, 3.0f));
	testPoint(Point(0.0f, 0.0f), Point(4.0f, 0.0f), Point(2.0f, 3.0f), Point(0.0f, 0.0f));
	testPoint(Point(0.0f, 0.0f), Point(5.0f, 0.0f), Point(2.5f, 5.0f), Point(5.0f, 0.0f));

	// ❌ Invalid Triangles (Collinear)
	testPoint(Point(0.0f, 0.0f), Point(2.0f, 2.0f), Point(4.0f, 4.0f), Point(2.0f, 2.0f));
	testPoint(Point(1.0f, 1.0f), Point(3.0f, 3.0f), Point(5.0f, 5.0f), Point(3.0f, 3.0f));
	testPoint(Point(0.0f, 0.0f), Point(5.0f, 0.0f), Point(10.0f, 0.0f), Point(5.0f, 0.0f));
	testPoint(Point(-3.0f, -3.0f), Point(0.0f, 0.0f), Point(3.0f, 3.0f), Point(0.0f, 0.0f));

	return (0);
}

