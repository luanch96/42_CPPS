/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:42:49 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:37:58 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "[Cat] Constructor por defecto" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
    std::cout << "[Cat] Constructor copia" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] Operador de asignación" << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "[Cat] Miau miau!" << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea) {
    _brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const {
    return _brain->getIdea(idx);
} 