/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:42:02 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:37:31 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << "[AAnimal] Constructor por defecto" << std::endl;
}

AAnimal::AAnimal(std::string const &type) : _type(type) {
    std::cout << "[AAnimal] Constructor con tipo" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
    std::cout << "[AAnimal] Constructor copia" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "[AAnimal] Operador de asignación" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "[AAnimal] Destructor" << std::endl;
}

std::string AAnimal::getType() const {
    return _type;
} 