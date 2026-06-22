/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:39:48 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:34:08 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "[WrongCat] Constructor por defecto" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] Constructor copia" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat] Operador de asignación" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] Destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat] Miau equivocado!" << std::endl;
} 