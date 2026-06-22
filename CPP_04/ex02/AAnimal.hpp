/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:42:10 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:37:01 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
protected:
    std::string _type;
public:
    AAnimal();
    AAnimal(std::string const &type);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();
    std::string getType() const;
    virtual void makeSound() const = 0;
};

#endif 