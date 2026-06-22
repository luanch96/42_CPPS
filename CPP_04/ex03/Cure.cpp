/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:44:41 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 11:44:44 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "[Cure] Constructor por defecto" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "[Cure] Constructor copia" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "[Cure] Operador de asignación" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Cure::~Cure() {
    std::cout << "[Cure] Destructor" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
} 