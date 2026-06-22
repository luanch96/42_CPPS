/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:45:48 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 11:45:51 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    std::cout << "[MateriaSource] Constructor por defecto" << std::endl;
    for (int i = 0; i < 4; ++i)
        materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "[MateriaSource] Constructor copia" << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = 0;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "[MateriaSource] Operador de asignación" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            if (materias[i])
                delete materias[i];
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "[MateriaSource] Destructor" << std::endl;
    for (int i = 0; i < 4; ++i)
        if (materias[i])
            delete materias[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!materias[i]) {
            materias[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return 0;
} 