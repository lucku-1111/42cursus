/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:30:53 by seoklee           #+#    #+#             */
/*   Updated: 2023/07/09 03:25:55 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_first_name(std::string str)
{
	first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	nickname = str;
}

void	Contact::set_phone_number(std::string str)
{
	phone_number = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	darkest_secret = str;
}

void	Contact::print_info(void)
{
	if (first_name.length() > 10)
		std::cout << first_name.substr(0, 9) << "." << " | ";
	else
		std::cout << std::setw(10) << first_name << " | ";

	if (last_name.length() > 10)
		std::cout << last_name.substr(0, 9) << "." << " | ";
	else
		std::cout << std::setw(10) << last_name << " | ";

	if (nickname.length() > 10)
		std::cout << nickname.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << nickname;

	std::cout << std::endl;
}

void	Contact::print_contact(void)
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}
