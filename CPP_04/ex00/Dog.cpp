/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:49 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 12:36:06 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "[Dog] Constructor por defecto" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] Constructor copia" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Operador de asignación" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Guau guau!" << std::endl;
} 