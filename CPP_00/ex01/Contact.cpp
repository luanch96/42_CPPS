/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:03:32 by luis              #+#    #+#             */
/*   Updated: 2025/04/16 22:38:57 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


void Contact::start_info(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkestsecret)
{
	this->index = index;
	this->first_name = first_name;
	this->nickname = nickname;
	this->last_name = last_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkestsecret;
}
void Contact::printinfo(void)
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nick name: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}

static void lineformat(std::string info)
{
	if(info.length() > 10)
	{
		std::cout << info.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::right << std::setw(10) << info;
	}
}
void Contact::printline(void)
{
	std::cout << "|" << std::right << std::setw(10) << this->index;
	std::cout << "|";
	lineformat(this->first_name);
	std::cout << "|";
	lineformat(this->last_name);
	std::cout << "|";
	lineformat(this->nickname);
	std::cout << "|";
	std::cout << std::endl;
}
/*
void Contact::putfirstname(std::string &first_name)
{
	this->first_name = first_name;
}

void Contact::putlastname(std::string &last_name)
{
	this->last_name = last_name;
}

void Contact::putnickname(std::string &nickname)
{
	this->nickname = nickname;
}

void Contact::putphone_number(std::string &phone_number)
{
	this->phone_number = phone_number;
}


void Contact::putdarkest_secret(std::string &darkest_secret)
{
	this->darkest_secret = darkest_secret;
}


std::string Contact::getfirstname(void)
{
	return this->first_name;
}

std::string Contact::getlastname(void)
{
	return this->last_name;
}


std::string Contact::getnickname(void)
{
	return this->nickname;
}


std::string Contact::getphone_number(void)
{
	return this->phone_number;
}


std::string Contact::getdarkest_secret(void)
{
	return this->darkest_secret;
}
*/