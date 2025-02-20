/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 03:51:36 by discallow         #+#    #+#             */
/*   Updated: 2025/02/19 16:25:24 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixedPointNum(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointNum = other._fixedPointNum;
}

Fixed::Fixed(const int n) {
	_fixedPointNum = n << _fracBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) {
	_fixedPointNum = roundf(n * (1 << _fracBits));
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat(void) const {
	return ((float)_fixedPointNum / (float)(1 << _fracBits));
}

int		Fixed::toInt(void) const {
	return (_fixedPointNum >> _fracBits);
}

Fixed &Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointNum = other._fixedPointNum;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNum);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointNum = raw;
}

Fixed	operator+(const Fixed& a, const Fixed& b) {
	return (Fixed(a.toFloat() + b.toFloat()));
}

Fixed	operator-(const Fixed& a, const Fixed& b) {
	return (Fixed(a.toFloat() - b.toFloat()));
}

Fixed	operator*(const Fixed& a, const Fixed& b) {
	return (Fixed(a.toFloat() * b.toFloat()));
}

Fixed	operator/(const Fixed& a, const Fixed& b) {
	return (Fixed(a.toFloat() / b.toFloat()));
}

bool	operator>(const Fixed& a, const Fixed& b) {
	return (a.toFloat() > b.toFloat());
}

bool	operator<(const Fixed& a, const Fixed& b) {
	return (a.toFloat() < b.toFloat());
}

bool	operator>=(const Fixed& a, const Fixed& b) {
	return (a.toFloat() >= b.toFloat());
}

bool	operator<=(const Fixed& a, const Fixed& b) {
	return (a.toFloat() <= b.toFloat());
}

bool	operator==(const Fixed& a, const Fixed& b) {
	return (a.toFloat() == b.toFloat());
}

bool	operator!=(const Fixed& a, const Fixed& b) {
	return (a.toFloat() != b.toFloat());
}

Fixed& Fixed::operator++(void) {
	_fixedPointNum++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_fixedPointNum++;
	return (*this);
}

Fixed& Fixed::operator--(void) {
	_fixedPointNum--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	_fixedPointNum--;
	return (*this);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a._fixedPointNum > b._fixedPointNum)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a._fixedPointNum > b._fixedPointNum)
		return (b);
	return (a);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a._fixedPointNum > b._fixedPointNum)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a._fixedPointNum > b._fixedPointNum)
		return (a);
	return (b);
}