/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:23:43 by luis              #+#    #+#             */
/*   Updated: 2025/05/06 13:23:47 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "\n=== Testing ScavTrap Construction ===" << std::endl;
    ScavTrap a;
    ScavTrap b("Bob");
    ScavTrap c(b);

    std::cout << "\n=== Testing ScavTrap Functions ===" << std::endl;
    a.attack("Enemy");
    b.attack("Enemy");
    
    a.takeDamage(50);
    b.takeDamage(50);
    
    a.beRepaired(30);
    b.beRepaired(30);
    
    std::cout << "\n=== Testing Gate Keeper Mode ===" << std::endl;
    a.guardGate();
    b.guardGate();
    
    std::cout << "\n=== Testing Death and Recovery ===" << std::endl;
    a.takeDamage(100);
    a.attack("Enemy");
    a.beRepaired(50);
    a.guardGate();
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 52; i++) {
        b.attack("Enemy");
    }
    
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    ScavTrap d;
    d = b;
    d.attack("Enemy");
    d.guardGate();
    
    return 0;
} 