/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:18:47 by luis              #+#    #+#             */
/*   Updated: 2025/04/28 18:57:15 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;
    
    public:
        Zombie();                    // Constructor por defecto
        Zombie(std::string name);    // Constructor con nombre
        ~Zombie();                   // Destructor
        void announce(void);         // Anunciar zombie
        void setName(std::string name); // Establecer nombre
};

// Función para crear la horda
Zombie* zombieHorde(int N, std::string name);

#endif

