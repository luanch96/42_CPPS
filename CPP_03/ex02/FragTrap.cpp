/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:25:20 by luis              #+#    #+#             */
/*   Updated: 2025/05/08 11:34:41 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " has no energy points left!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " is dead and cannot request high fives!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " requests a positive high five!" << std::endl;
} 