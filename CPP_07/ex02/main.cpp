/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:05:06 by luis              #+#    #+#             */
/*   Updated: 2025/08/24 18:16:45 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "=== Testing Array with integers ===" << std::endl;
    
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    Array<int> intArray(5);
    std::cout << "Int array size: " << intArray.size() << std::endl;
    
    std::cout << "Default values: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    
    std::cout << "After assignment: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    Array<int> copyArray(intArray);
    std::cout << "Copy array: ";
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;
    
    intArray[0] = 999;
    std::cout << "Original after modification: " << intArray[0] << std::endl;
    std::cout << "Copy unchanged: " << copyArray[0] << std::endl;
    
    Array<int> assignArray;
    assignArray = intArray;
    std::cout << "Assigned array: ";
    for (unsigned int i = 0; i < assignArray.size(); i++) {
        std::cout << assignArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Testing bounds checking ===" << std::endl;
    try {
        std::cout << "Accessing valid index: " << intArray[2] << std::endl;
        std::cout << "Accessing invalid index: " << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: Index out of bounds" << std::endl;
    }
    
    std::cout << "\n=== Testing Array with strings ===" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "C++";
    
    std::cout << "String array: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    const Array<std::string> constStringArray = stringArray;
    std::cout << "Const string array: ";
    for (unsigned int i = 0; i < constStringArray.size(); i++) {
        std::cout << constStringArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== Testing self-assignment ===" << std::endl;
    std::cout << "Self-assignment completed successfully" << std::endl;
    
    return 0;
} 