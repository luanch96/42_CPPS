/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:55:26 by luis              #+#    #+#             */
/*   Updated: 2025/08/15 11:55:57 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>

int main() {
    std::cout << "Testing type identification with randomly generated objects:" << std::endl;
    std::cout << "=========================================================" << std::endl;
    
    for (int i = 0; i < 10; i++) {
        std::cout << "Test " << (i + 1) << ":" << std::endl;
        
        Base* ptr = generate();
        
        std::cout << "  Pointer identification: ";
        identify(ptr);
        
        std::cout << "  Reference identification: ";
        identify(*ptr);
        
        delete ptr;
        std::cout << std::endl;
    }
    
    return 0;
} 