/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:57:01 by luis              #+#    #+#             */
/*   Updated: 2025/04/28 18:57:05 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor por defecto
Zombie::Zombie() {
    this->name = "unnamed";
    std::cout << "Zombie " << this->name << " created" << std::endl;
}

// Constructor con nombre
Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " created" << std::endl;
}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

// Método para anunciar
void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Método para establecer nombre
void Zombie::setName(std::string name) {
    this->name = name;
}

