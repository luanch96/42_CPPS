/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:04:22 by luis              #+#    #+#             */
/*   Updated: 2025/08/24 18:07:35 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template<typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

template<typename T>
void printElementConst(const T& element) {
    std::cout << element << " ";
}

template<typename T>
void multiplyByTwo(T& element) {
    element = element * 2;
}

template<typename T>
void toUpperCase(T& element) {
    for (size_t i = 0; i < element.length(); i++) {
        if (element[i] >= 'a' && element[i] <= 'z') {
            element[i] = element[i] - 32;
        }
    }
}

int main() {
    std::cout << "=== Testing with integers ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original array: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intLength, multiplyByTwo<int>);
    std::cout << "After multiplying by 2: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;
    
    std::cout << "\n=== Testing with const integers ===" << std::endl;
    const int constIntArray[] = {10, 20, 30, 40, 50};
    size_t constIntLength = sizeof(constIntArray) / sizeof(constIntArray[0]);
    
    std::cout << "Const array: ";
    iter(constIntArray, constIntLength, printElementConst<int>);
    std::cout << std::endl;
    
    std::cout << "\n=== Testing with strings ===" << std::endl;
    std::string stringArray[] = {"hello", "world", "cpp", "module"};
    size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Original strings: ";
    iter(stringArray, stringLength, printElement<std::string>);
    std::cout << std::endl;
    
    iter(stringArray, stringLength, toUpperCase<std::string>);
    std::cout << "After toUpperCase: ";
    iter(stringArray, stringLength, printElement<std::string>);
    std::cout << std::endl;
    
    std::cout << "\n=== Testing with const strings ===" << std::endl;
    const std::string constStringArray[] = {"const", "test", "strings"};
    size_t constStringLength = sizeof(constStringArray) / sizeof(constStringArray[0]);
    
    std::cout << "Const strings: ";
    iter(constStringArray, constStringLength, printElementConst<std::string>);
    std::cout << std::endl;
    
    std::cout << "\n=== Testing with doubles ===" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Original doubles: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;
    
    iter(doubleArray, doubleLength, multiplyByTwo<double>);
    std::cout << "After multiplying by 2: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;
    
    return 0;
}