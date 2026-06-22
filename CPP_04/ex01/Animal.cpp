/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:40:37 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:35:12 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "[Animal] Constructor por defecto" << std::endl;
}

Animal::Animal(std::string const &type) : _type(type) {
    std::cout << "[Animal] Constructor con tipo" << std::endl;
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