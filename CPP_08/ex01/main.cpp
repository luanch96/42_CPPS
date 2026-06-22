/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:34:21 by luis              #+#    #+#             */
/*   Updated: 2025/09/11 16:59:55 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "=== Testing Span class ===" << std::endl;
    
    std::cout << "\n--- Test 1: Basic functionality ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 2: Exception handling for full span ---" << std::endl;
    try {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << "Added 3 numbers successfully" << std::endl;
        
        sp.addNumber(4);
        std::cout << "This shouldn't print" << std::endl;
    } catch (const Span::SpanFullException& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 3: Exception handling for insufficient numbers ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(1);
        
        unsigned int span = sp.shortestSpan();
        std::cout << "This shouldn't print: " << span << std::endl;
    } catch (const Span::NoSpanException& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 4: Testing with range of iterators ---" << std::endl;
    try {
        Span sp = Span(10);
        std::vector<int> numbers;
        numbers.push_back(100);
        numbers.push_back(200);
        numbers.push_back(300);
        numbers.push_back(400);
        numbers.push_back(500);
        
        sp.addRange(numbers.begin(), numbers.end());
        std::cout << "Added range of numbers successfully" << std::endl;
        std::cout << "Current size: " << sp.getCurrentSize() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 5: Testing with 10,000+ numbers ---" << std::endl;
    try {
        Span sp = Span(15000);
        
        std::srand(std::time(0));
        std::vector<int> largeNumbers;
        for (int i = 0; i < 15000; ++i) {
            largeNumbers.push_back(std::rand() % 1000000);
        }
        
        sp.addRange(largeNumbers.begin(), largeNumbers.end());
        std::cout << "Successfully added 15,000 numbers!" << std::endl;
        std::cout << "Current size: " << sp.getCurrentSize() << std::endl;
        std::cout << "Max size: " << sp.getMaxSize() << std::endl;
        
        std::cout << "Calculating shortest span..." << std::endl;
        unsigned int shortest = sp.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;
        
        std::cout << "Calculating longest span..." << std::endl;
        unsigned int longest = sp.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 6: Edge cases ---" << std::endl;
    try {
        Span sp1 = Span(0);
        std::cout << "Created span with max size 0" << std::endl;
        
        try {
            sp1.addNumber(1);
        } catch (const Span::SpanFullException& e) {
            std::cout << "Correctly caught exception for empty span: " << e.what() << std::endl;
        }
        
        Span sp2 = Span(1);
        sp2.addNumber(42);
        std::cout << "Added number to span of size 1" << std::endl;
        
        try {
            sp2.shortestSpan();
        } catch (const Span::NoSpanException& e) {
            std::cout << "Correctly caught exception for single number: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 7: Copy constructor and assignment operator ---" << std::endl;
    try {
        Span original = Span(5);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);
        
        Span copy(original);
        std::cout << "Copy constructor: Original size: " << original.getCurrentSize() 
                  << ", Copy size: " << copy.getCurrentSize() << std::endl;
        
        Span assigned = Span(10);
        assigned = original;
        std::cout << "Assignment operator: Original size: " << original.getCurrentSize() 
                  << ", Assigned size: " << assigned.getCurrentSize() << std::endl;
        
        copy.addNumber(40);
        std::cout << "After adding to copy: Original size: " << original.getCurrentSize() 
                  << ", Copy size: " << copy.getCurrentSize() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
} 