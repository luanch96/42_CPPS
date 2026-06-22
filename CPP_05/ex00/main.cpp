/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:47:47 by luis              #+#    #+#             */
/*   Updated: 2025/06/12 11:47:50 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // Test valid bureaucrat creation
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        // Test grade increment
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        // Test grade decrement
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;

        // Test copy constructor
        Bureaucrat copyJohn(john);
        std::cout << "Copy: " << copyJohn << std::endl;

        // Test assignment operator
        Bureaucrat mike("Mike", 100);
        std::cout << "Before assignment: " << mike << std::endl;
        mike = john;
        std::cout << "After assignment: " << mike << std::endl;

        // Test invalid grade (too high)
        try {
            Bureaucrat highGrade("High", 0);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test invalid grade (too low)
        try {
            Bureaucrat lowGrade("Low", 151);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test incrementing highest grade
        Bureaucrat highest("Highest", 1);
        try {
            highest.incrementGrade();
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test decrementing lowest grade
        Bureaucrat lowest("Lowest", 150);
        try {
            lowest.decrementGrade();
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
} 