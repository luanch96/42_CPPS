/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:30:21 by luis              #+#    #+#             */
/*   Updated: 2025/04/21 12:30:33 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <fstream>

void	replacing_loop(std::istream &infile, std::ostream &outfile, std::string original, std::string replace)
{
	std::string	line;
	size_t	aux1;
	size_t	aux2;

	while (std::getline(infile, line))
	{
		aux1 = 0;
		aux2 = line.find(original, aux1);
		while (aux2 != std::string::npos)
		{
			outfile << line.substr(aux1, aux2 - aux1) << replace;
			aux1 = aux2 + original.size();
			aux2 = line.find(original, aux1);
		}
		outfile << line.substr(aux1, line.size());
		if (!infile.eof())
			outfile << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}

	std::string	original = (std::string)argv[2];
	std::string	replace = (std::string)argv[3];
	std::string	in = (std::string)argv[1];
	std::string	out = in + ".replace";

	if (original.empty())
	{
		std::cout << "String to be replaced can't be empty" << std::endl;
		return (1);
	}

	std::ifstream infile;
	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "Error opening infile" << std::endl;
		return (1);
	}

	std::ofstream outfile;
	outfile.open(out.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error opening outfile" << std::endl;
		return (1);
	}

	replacing_loop(infile, outfile, original, replace);
	return (0);
}