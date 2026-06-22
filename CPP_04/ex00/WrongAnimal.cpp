/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:39:33 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:34:00 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "[WrongAnimal] Constructor por defecto" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type) {
    std::cout << "[WrongAnimal] Constructor con tipo" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "[WrongAnimal] Constructor copia" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "[WrongAnimal] Operador de asignación" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] Destructor" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] *sonido equivocado*" << std::endl;
} 