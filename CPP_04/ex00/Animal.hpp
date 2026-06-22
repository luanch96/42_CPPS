/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:24 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 12:04:30 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string _type;
public:
    Animal();
    Animal(std::string const &type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const;
};

#endif 