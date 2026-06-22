/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:35:25 by luis              #+#    #+#             */
/*   Updated: 2025/09/11 16:57:02 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <iostream>
#include <list>
#include <stack>

int main() {
    std::cout << "=== Testing MutantStack class ===" << std::endl;
    
    std::cout << "\n--- Test 1: Basic functionality with MutantStack ---" << std::endl;
    try {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "Top element: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        std::cout << "Iterating through MutantStack:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        
        std::stack<int> s(mstack);
        std::cout << "Converted to std::stack, size: " << s.size() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 2: Comparison with std::list ---" << std::endl;
    try {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << "Last element: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "Size after pop: " << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::cout << "Iterating through std::list:" << std::endl;
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 3: Testing all iterator types ---" << std::endl;
    try {
        MutantStack<int> mstack;
        for (int i = 1; i <= 5; ++i) {
            mstack.push(i);
        }
        
        std::cout << "Forward iteration:" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Reverse iteration:" << std::endl;
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Const forward iteration:" << std::endl;
        const MutantStack<int>& const_mstack = mstack;
        for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 4: Testing with different data types ---" << std::endl;
    try {
        MutantStack<std::string> stringStack;
        stringStack.push("Hello");
        stringStack.push("World");
        stringStack.push("C++");
        stringStack.push("Module");
        stringStack.push("08");
        
        std::cout << "String stack iteration:" << std::endl;
        for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        MutantStack<double> doubleStack;
        doubleStack.push(3.14);
        doubleStack.push(2.718);
        doubleStack.push(1.618);
        
        std::cout << "Double stack iteration:" << std::endl;
        for (MutantStack<double>::iterator it = doubleStack.begin(); it != doubleStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 5: Testing copy constructor and assignment operator ---" << std::endl;
    try {
        MutantStack<int> original;
        original.push(10);
        original.push(20);
        original.push(30);
        
        MutantStack<int> copy(original);
        std::cout << "Copy constructor - Original size: " << original.size() 
                  << ", Copy size: " << copy.size() << std::endl;
        
        MutantStack<int> assigned;
        assigned = original;
        std::cout << "Assignment operator - Original size: " << original.size() 
                  << ", Assigned size: " << assigned.size() << std::endl;
        

        copy.push(40);
        std::cout << "After adding to copy - Original size: " << original.size() 
                  << ", Copy size: " << copy.size() << std::endl;
        
        std::cout << "Original stack: ";
        for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copy stack: ";
        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Test 6: Edge cases ---" << std::endl;
    try {
        MutantStack<int> emptyStack;
        std::cout << "Empty stack size: " << emptyStack.size() << std::endl;
        
        std::cout << "Iterating empty stack: ";
        for (MutantStack<int>::iterator it = emptyStack.begin(); it != emptyStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "(no output expected)" << std::endl;
        
        MutantStack<int> singleStack;
        singleStack.push(42);
        std::cout << "Single element stack: ";
        for (MutantStack<int>::iterator it = singleStack.begin(); it != singleStack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
} 