/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:39:39 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:34:20 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(std::string const &type);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();
    std::string getType() const;
    void makeSound() const;
};

#endif 