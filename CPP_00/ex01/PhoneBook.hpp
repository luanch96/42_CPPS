/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:02:40 by luis              #+#    #+#             */
/*   Updated: 2025/04/16 22:03:25 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int number;
	public:
		PhoneBook();
		void addcontact(std::string &first_name, std::string &last_name, std::string &nickname, std::string &phonenumber, std::string &darkest_secret);
		void print_list();
		void print_contact(std::string input);
};

#endif

