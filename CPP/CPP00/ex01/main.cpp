/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:20:11 by seoklee           #+#    #+#             */
/*   Updated: 2023/07/10 17:34:49 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	str;

	while (1)
	{
		std::cout << "Enter: ";
		phone_book.get_input(str);
		if (str.empty() || std::cin.eof())
		{
			std::cout << "Wrong input. Try again." << std::endl;
			continue ;
		}
		if (str == "ADD")
			phone_book.add();
		else if (str == "SEARCH")
			phone_book.search();
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}