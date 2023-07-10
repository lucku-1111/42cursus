/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:55:12 by seoklee           #+#    #+#             */
/*   Updated: 2023/06/25 22:16:38 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != 0; j++)
		{
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
	}
	std::cout << std::endl;
	return (0);
}