/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:14 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 12:05:03 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "[Animal] Constructor por defecto" << std::endl;
}

Animal::Animal(std::string const &type) {
    this->_type = type;
}

Animal::Animal(const Animal& other) : _type(other._type) {
    std::cout << "[Animal] Constructor copia" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Operador de asignación" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "[Animal] *sonido genérico*" << std::endl;
} 