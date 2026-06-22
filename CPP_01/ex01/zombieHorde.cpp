/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:19:38 by luis              #+#    #+#             */
/*   Updated: 2025/04/22 13:54:02 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) {
        std::cout << "Cannot create a horde with " << N << " zombies" << std::endl;
        return NULL;
    }

    // Crear array de zombies
    Zombie* horde = new Zombie[N];
    
    // Asignar nombre a cada zombie
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    
    return horde;
}

