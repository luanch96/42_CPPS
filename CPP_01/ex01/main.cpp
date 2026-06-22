/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:18:07 by luis              #+#    #+#             */
/*   Updated: 2025/04/22 13:23:27 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;  // Tamaño de la horda
    
    // Crear la horda
    Zombie* horde = zombieHorde(N, "HordeZombie");
    if (!horde) {
        return 1;
    }
    
    // Hacer que cada zombie se anuncie
    for (int i = 0; i < N; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    
    // Liberar la memoria
    delete[] horde;
    
    return 0;
}

