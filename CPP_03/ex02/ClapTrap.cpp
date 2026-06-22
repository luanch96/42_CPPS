/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:24:56 by luis              #+#    #+#             */
/*   Updated: 2025/05/08 11:36:23 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(100), _energyPoints(100), _attackDamage(30) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(30) {
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " points of damage and dies!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " is repaired for " << amount 
              << " hit points!" << std::endl;
} 