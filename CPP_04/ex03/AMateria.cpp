/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:52 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:39:17 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("AMateria") {
    std::cout << "[AMateria] Constructor por defecto" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "[AMateria] Constructor: " << type << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "[AMateria] Constructor copia: " << _type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "[AMateria] Operador de asignación" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "[AMateria] Destructor: " << _type << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "[AMateria] Se usa materia base" << std::endl;
    //std::cout << "AMateria " << this->_type << "used in" << target.getName() << "." << std::endl;
} 