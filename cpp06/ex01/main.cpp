/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:41:56 by discallow         #+#    #+#             */
/*   Updated: 2025/03/26 18:46:27 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data original(123);

	std::cout << "Original Data value: " << original.getValue() << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Data value: " << deserialized->getValue() << std::endl;

	if (&original == deserialized)
		std::cout << "Success: The deserialized object matches the original!" << std::endl;
	else
		std::cout << "Error: The deserialized object does not match the original." << std::endl;
    return (0);
}