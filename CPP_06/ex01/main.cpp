/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:52:26 by luis              #+#    #+#             */
/*   Updated: 2025/08/15 11:52:31 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data original(42, "Hello World!", 3.14159);
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Number: " << original.number << std::endl;
    std::cout << "  Text: " << original.text << std::endl;
    std::cout << "  Value: " << original.value << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << std::endl;
    
    if (deserialized == &original) {
        std::cout << "SUCCESS: The deserialized pointer equals the original pointer!" << std::endl;
    } else {
        std::cout << "ERROR: The deserialized pointer does not equal the original pointer!" << std::endl;
        return 1;
    }
    
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "  Number: " << deserialized->number << std::endl;
    std::cout << "  Text: " << deserialized->text << std::endl;
    std::cout << "  Value: " << deserialized->value << std::endl;
    
    return 0;
} 