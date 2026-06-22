/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:33 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 11:43:36 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- Prueba básica de destrucción polimórfica ---" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    std::cout << "\n--- Prueba array de AAnimal* ---" << std::endl;
    const int N = 6;
    AAnimal* animals[N];
    for (int k = 0; k < N; ++k) {
        if (k < N/2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    for (int k = 0; k < N; ++k)
        animals[k]->makeSound();
    for (int k = 0; k < N; ++k)
        delete animals[k];

    std::cout << "\n--- Prueba de deep copy (Dog) ---" << std::endl;
    Dog d1;
    d1.setIdea(0, "Correr tras la pelota");
    Dog d2(d1);
    std::cout << "d1 idea: " << d1.getIdea(0) << std::endl;
    std::cout << "d2 idea: " << d2.getIdea(0) << std::endl;
    d2.setIdea(0, "Dormir");
    std::cout << "d1 idea tras cambio en d2: " << d1.getIdea(0) << std::endl;
    std::cout << "d2 idea tras cambio: " << d2.getIdea(0) << std::endl;

    std::cout << "\n--- Prueba de deep copy (Cat) ---" << std::endl;
    Cat c1;
    c1.setIdea(1, "Cazar ratones");
    Cat c2;
    c2 = c1;
    std::cout << "c1 idea: " << c1.getIdea(1) << std::endl;
    std::cout << "c2 idea: " << c2.getIdea(1) << std::endl;
    c2.setIdea(1, "Dormir al sol");
    std::cout << "c1 idea tras cambio en c2: " << c1.getIdea(1) << std::endl;
    std::cout << "c2 idea tras cambio: " << c2.getIdea(1) << std::endl;

    // No se puede instanciar AAnimal:
    // AAnimal a; // Esto debe dar error de compilación

    return 0;
} 