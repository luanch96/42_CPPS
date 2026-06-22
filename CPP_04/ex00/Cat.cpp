/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:33 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 12:35:54 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "[Cat] Constructor por defecto" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] Constructor copia" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] Operador de asignación" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Miau miau!" << std::endl;
} 