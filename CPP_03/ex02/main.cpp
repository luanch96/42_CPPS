/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:25:51 by luis              #+#    #+#             */
/*   Updated: 2025/05/06 13:26:00 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "\n=== Testing FragTrap Construction ===" << std::endl;
    FragTrap a;
    FragTrap b("Bob");
    FragTrap c(b);

    std::cout << "\n=== Testing FragTrap Functions ===" << std::endl;
    a.attack("Enemy");
    b.attack("Enemy");
    
    a.takeDamage(50);
    b.takeDamage(50);
    
    a.beRepaired(30);
    b.beRepaired(30);
    
    std::cout << "\n=== Testing High Fives ===" << std::endl;
    a.highFivesGuys();
    b.highFivesGuys();
    
    std::cout << "\n=== Testing Death and Recovery ===" << std::endl;
    a.takeDamage(100);
    a.attack("Enemy");
    a.beRepaired(50);
    a.highFivesGuys();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 102; i++) {
        b.attack("Enemy");
    }
    
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    FragTrap d;
    d = b;
    d.attack("Enemy");
    d.highFivesGuys();
    
    return 0;
} 