/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 03:53:22 by discallow         #+#    #+#             */
/*   Updated: 2025/02/10 17:23:44 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	replaceLine(const std::string& s1, const std::string& s2, std::string& line) {
	size_t	pos = 0;
	while (1) {
		pos = line.find(s1, pos);
		if (pos == std::string::npos)
			return ;
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos += s2.length();
	}
}

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Number of arguments invalid." << std::endl;
		return (1);
	}
	std::string		input = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		line;
	std::ifstream	oldFile(input.c_str());
	if (!oldFile)
		return (std::cerr << "Error opening file." << std::endl, 1);
	std::string	replaceFile = input.append(".replace");
	std::ofstream	outputFile(replaceFile.c_str());
	if (!outputFile)
		return (std::cerr << "Error creating new file." << std::endl, 1);
	while (std::getline(oldFile, line)) {
		replaceLine(s1, s2, line);
		outputFile << line << '\n';
	}
	oldFile.close();
	outputFile.close();
	
	return (0);
}