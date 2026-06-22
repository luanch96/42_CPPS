/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:20:01 by luis              #+#    #+#             */
/*   Updated: 2025/05/06 13:20:09 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main() {
    std::cout << "\n=== Testing ClapTrap Construction ===" << std::endl;
    ClapTrap a("luna");
    ClapTrap b("Bob");
    ClapTrap c(b);

    std::cout << "\n=== Testing ClapTrap Functions ===" << std::endl;
    a.attack("Bob");
    b.attack("Luna");
    
    a.takeDamage(5);
    b.takeDamage(5);
    
    a.beRepaired(3);
    b.beRepaired(3);
    
    std::cout << "\n=== Testing Death and Recovery ===" << std::endl;
    a.takeDamage(10);
    a.attack("Enemy");
    a.beRepaired(5);
    
    std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
    for (int i = 0; i < 12; i++) {
        b.attack("Enemy");
    }
    
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    ClapTrap d;
    d = b;
    d.attack("Enemy");
    
    return 0;
} 