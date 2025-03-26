/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:38:20 by discallow         #+#    #+#             */
/*   Updated: 2025/03/26 18:39:40 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data {
	private:
		int value;
	public:
		Data(void);
		Data(const Data &other);
		Data(int value);
		Data    &operator=(const Data &other);
		~Data(void);
		int getValue() const;
};

#endif