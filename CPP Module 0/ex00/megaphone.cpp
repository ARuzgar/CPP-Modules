/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerbosna <aerbosna@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:44:38 by aerbosna          #+#    #+#             */
/*   Updated: 2023/05/24 11:44:39 by aerbosna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "Not enough arguments." << std::endl;
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (unsigned long j = 0; j < std::strlen(av[i]); j++)
			{
				char c = std::toupper(av[i][j]);
				std::cout << c;
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
