/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:33:51 by luis              #+#    #+#             */
/*   Updated: 2025/09/11 17:00:30 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
    std::cout << "=== Testing easyfind with different containers ===" << std::endl;
    
    std::cout << "\n--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);
    }
    std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found 5 at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 15);
        std::cout << "Found 15 at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it;
        std::list<int>::iterator next_it = it;
        ++next_it;
        if (next_it != lst.end()) std::cout << ", ";
    }
    std::cout << std::endl;
    
    try {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Found 30 at position: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found 100 at position: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Testing with std::deque ---" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);
    std::cout << "Deque: ";
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i];
        if (i < deq.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
    
    try {
        std::deque<int>::iterator it = easyfind(deq, 300);
        std::cout << "Found 300 at position: " << std::distance(deq.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Testing edge cases ---" << std::endl;
    
    std::vector<int> empty_vec;
    std::cout << "Testing with empty vector..." << std::endl;
    try {
        easyfind(empty_vec, 1);
        std::cout << "Found 1 in empty vector (this shouldn't happen!)" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Expected error with empty vector: " << e.what() << std::endl;
    }
    
    std::vector<int> dup_vec;
    dup_vec.push_back(1);
    dup_vec.push_back(2);
    dup_vec.push_back(2);
    dup_vec.push_back(3);
    dup_vec.push_back(2);
    dup_vec.push_back(4);
    std::cout << "Vector with duplicates: ";
    for (size_t i = 0; i < dup_vec.size(); ++i) {
        std::cout << dup_vec[i];
        if (i < dup_vec.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
    
    try {
        std::vector<int>::iterator it = easyfind(dup_vec, 2);
        std::cout << "Found first occurrence of 2 at position: " << std::distance(dup_vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
} 