/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:35:30 by seoklee           #+#    #+#             */
/*   Updated: 2023/07/10 17:21:05 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <sstream>

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		last;
		int		count;
	public:
		PhoneBook(void);
		void	get_input(std::string &str);
		void	add(void);
		void	search(void);
		int		set_contact(Contact &contact);
};

#endif