/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:14 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:38:09 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    _brain = new Brain();
    std::cout << "[Dog] Constructor por defecto" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other) {
    std::cout << "[Dog] Constructor copia" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Operador de asignación" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] Destructor" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    std::cout << "[Dog] Guau guau!" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea) {
    _brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const {
    return _brain->getIdea(idx);
} 