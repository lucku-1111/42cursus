/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:30:51 by seoklee           #+#    #+#             */
/*   Updated: 2023/07/10 19:40:31 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	last = -1;
	count = 0;
}

void	PhoneBook::get_input(std::string &str)
{
	std::cin.clear();
	std::clearerr(stdin);
	std::getline(std::cin, str);
}

void	PhoneBook::add(void)
{
	if  (last < 7)
		last++;
	else if (last == 7)
		last = 0;
	while (PhoneBook::set_contact(contacts[last]))
		std::cout << "Wrong input. Try again." << std::endl;
	if (count < 8)
		count++;
}

int	PhoneBook::set_contact(Contact &contact)
{
	std::string	str;

	std::cout << "First name: ";
	PhoneBook::get_input(str);
	if (str.empty() || std::cin.eof())
		return (1);
	contact.set_first_name(str);

	std::cout << "last name: ";
	PhoneBook::get_input(str);
	if (str.empty() || std::cin.eof())
		return (1);
	contact.set_last_name(str);

	std::cout << "Nickname: ";
	PhoneBook::get_input(str);
	if (str.empty() || std::cin.eof())
		return (1);
	contact.set_nickname(str);

	std::cout << "Phone number: ";
	PhoneBook::get_input(str);
	if (str.empty() || std::cin.eof())
		return (1);
	contact.set_phone_number(str);

	std::cout << "Darkest secret: ";
	PhoneBook::get_input(str);
	if (str.empty() || std::cin.eof())
		return (1);
	contact.set_darkest_secret(str);
	return (0);
}

void	PhoneBook::search(void)
{
	std::string	str;
	int			index;

	if (last == -1)
	{
		std::cout << "Phone book is empty." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << " | ";
	std::cout << std::setw(10) << "First name" << " | ";
	std::cout << std::setw(10) << "Last name" << " | ";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << " | ";
		contacts[i].print_info();
	}

	while (1)
	{
		std::stringstream	ss;

		index = 0;
		std::cout << "Index: ";
		PhoneBook::get_input(str);
		ss << str;
		if (!(ss >> index) || ss >> index || str.empty() || std::cin.eof() || index < 0 || index >= count)
			std::cout << "Wrong input." << std::endl;
		else
			break ;
	}
	contacts[index].print_contact();
}
