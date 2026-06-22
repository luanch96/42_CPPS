/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:00:14 by luis              #+#    #+#             */
/*   Updated: 2025/04/16 22:52:25 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook()
{
	this->number = 0;
}

static bool is_number(const std::string number)
{
	for(std::size_t i = 0; i < number.size(); i++)
	{
		if(!isdigit(number[i]))
			return false;
	}
	return true;
}

void PhoneBook::addcontact(std::string &first_name, std::string &last_name, std::string &nickname, std::string &phonenumber, std::string &darkest_secret)
{
	if(first_name.empty() || last_name.empty() || nickname.empty() || phonenumber.empty() || darkest_secret.empty())
	{
		std::cout << "Error: All fields are required." << std::endl;
		std::cout << "Please enter the contact information again." << std::endl;
		return;
	}
	if(!is_number(phonenumber))
	{
		std::cout << "Error: Invalid phone number." << std::endl;
		std::cout << "Please enter the contact information again." << std::endl;
		return;
	}
	this->contact[this->number % 8].start_info(this->number % 8, first_name, last_name, nickname, phonenumber, darkest_secret);
	this->number += 1;
}
void PhoneBook::print_list()
{
	int num;

	if(this->number < 8)
		num = this->number;
	else
		num = 8;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for(int i = 0; i < num; i++)
	{
		this->contact[i].printline();
	}
}
void PhoneBook::print_contact(std::string input)
{
	int index;

	index = std::atoi(input.c_str());
	if(!is_number(input) || index < 0 || index >= 8 || index >= this->number -1)
	{
		std::cout << "Error: Invalid index." << std::endl;
	}
	else
	{
		this->contact[index].printinfo();
	}
}
