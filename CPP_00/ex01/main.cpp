/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:58:17 by luis              #+#    #+#             */
/*   Updated: 2025/04/17 11:38:05 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main(void)
{
	PhoneBook phonebook;
	std::string input, firstname, lastname, nickname, phone, darkestsecret;

	while(true)
	{
		std::cout << "*************************************************" << std::endl;
		std::cout << "*               Welcome to My Phonebook!        *" << std::endl;
		std::cout << "*************************************************" << std::endl;
		std::cout << "*               Select an option:               *" << std::endl;
		std::cout << "*               1. ADD                          *" << std::endl;
		std::cout << "*               2. SEARCH                       *" << std::endl;
		std::cout << "*               3. EXIT                         *" << std::endl;
		std::cout << "*************************************************" << std::endl;
		std::getline(std::cin, input);
		if(std::cin.eof())
			break;
		if(input == "ADD")
		{
			std::cout << "Enter first name: ";
			std::getline(std::cin, firstname);
			std::cout << "Enter last name: ";
			std::getline(std::cin, lastname);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phone);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestsecret);
			phonebook.addcontact(firstname, lastname, nickname, phone, darkestsecret);
		}
		else if(input == "SEARCH")
		{
			phonebook.print_list();
			std::cout << "Enter the index of the contact you want to search for: ";
			std::getline(std::cin, input);
			phonebook.print_contact(input);
		}
		else if(input == "EXIT")
			return (0);
		else
			std::cout << "Invalid input. Please try again." << std::endl;
	}
	return (0);
}
