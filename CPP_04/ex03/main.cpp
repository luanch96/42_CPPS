/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:45:33 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 11:45:36 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include <iostream>

int main() {
    std::cout << "--- Prueba oficial del enunciado ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << "\n--- Prueba de inventario lleno y uso/unequip ---" << std::endl;
    Character hero("hero");
    hero.equip(new Ice());
    hero.equip(new Cure());
    hero.equip(new Ice());
    hero.equip(new Cure());
    hero.equip(new Ice()); // No debe equipar
    hero.use(0, hero);
    hero.use(1, hero);
    hero.use(2, hero);
    hero.use(3, hero);
    hero.use(4, hero); // No debe hacer nada
    hero.unequip(1);
    hero.use(1, hero); // No debe hacer nada

    std::cout << "\n--- Prueba de deep copy de Character ---" << std::endl;
    Character c1("c1");
    c1.equip(new Ice());
    c1.equip(new Cure());
    Character c2 = c1;
    c1.use(0, c1);
    c2.use(0, c2);
    c2.unequip(0);
    c2.use(0, c2); // No debe hacer nada

    std::cout << "\n--- Prueba de MateriaSource con tipos desconocidos ---" << std::endl;
    MateriaSource ms;
    ms.learnMateria(new Ice());
    AMateria* unknown = ms.createMateria("fire");
    if (!unknown)
        std::cout << "No se pudo crear materia de tipo fire" << std::endl;

    // Liberar materias sueltas
    delete unknown;

    return 0;
} 