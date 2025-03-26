/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:39:56 by discallow         #+#    #+#             */
/*   Updated: 2025/03/26 18:56:29 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : value(42) {}

Data::Data(const Data &other): value(other.value) {}

Data::Data(int value) : value(value) {}

Data &Data::operator=(const Data &other) {
	if (this != &other)
		value = other.value;
	return (*this);
}

Data::~Data() {}

int Data::getValue() const {
        return (value);
}