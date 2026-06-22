/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:35:07 by luis              #+#    #+#             */
/*   Updated: 2025/05/13 12:35:12 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "[Ice] Constructor por defecto" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "[Ice] Constructor copia" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "[Ice] Operador de asignación" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {
    std::cout << "[Ice] Destructor" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
} 