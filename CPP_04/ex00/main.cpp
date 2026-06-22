/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:39:19 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/14 15:58:55 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- Prueba polimorfismo correcto ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Cat
    j->makeSound(); // Dog
    meta->makeSound(); // Animal
    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- Prueba polimorfismo incorrecto (WrongAnimal) ---" << std::endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wi = new WrongCat();
    std::cout << wi->getType() << " " << std::endl;
    wi->makeSound(); // WrongAnimal sound
    wmeta->makeSound(); // WrongAnimal sound
    delete wmeta;
    delete wi;

    std::cout << "\n--- Prueba constructores y asignación ---" << std::endl;
    Dog d1;
    Dog d2(d1);
    Dog d3;
    d3 = d1;
    Cat c1;
    Cat c2(c1);
    Cat c3;
    c3 = c1;

    std::cout << "\n--- Prueba array de Animal* ---" << std::endl;
    Animal* zoo[4];
    for (int k = 0; k < 4; ++k) {
        if (k % 2 == 0)
            zoo[k] = new Dog();
        else
            zoo[k] = new Cat();
    }
    for (int k = 0; k < 4; ++k) {
        zoo[k]->makeSound();
    }
    for (int k = 0; k < 4; ++k) {
        delete zoo[k];
    }

    return 0;
} 