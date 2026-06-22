/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:44:19 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:39:28 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name) {
    std::cout << "[Character] Constructor: " << _name << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

Character::Character(const Character& other) : _name(other._name) {
    std::cout << "[Character] Constructor copia: " << _name << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "[Character] Operador de asignación" << std::endl;
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; ++i) {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "[Character] Destructor: " << _name << std::endl;
    for (int i = 0; i < 4; ++i)
        if (_inventory[i])
            delete _inventory[i];
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
        return;
    _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
} 