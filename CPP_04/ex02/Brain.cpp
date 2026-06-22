/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:42:28 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:37:43 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] Constructor por defecto" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = "";
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] Constructor copia" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] Operador de asignación" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] Destructor" << std::endl;
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx >= 0 && idx < 100)
        _ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const {
    if (idx >= 0 && idx < 100)
        return _ideas[idx];
    return "";
} 