/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:48:30 by luis              #+#    #+#             */
/*   Updated: 2025/06/12 11:48:33 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Test valid bureaucrat and form creation
        Bureaucrat john("John", 50);
        Form form1("Tax Form", 60, 30);
        Form form2("Important Document", 40, 20);

        std::cout << john << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        // Test signing forms
        std::cout << "\nTesting form signing:" << std::endl;
        john.signForm(form1);  // Should succeed (grade 50 < 60)
        john.signForm(form2);  // Should fail (grade 50 > 40)

        // Test form copy and assignment
        Form form3(form1);
        std::cout << "\nCopied form: " << form3 << std::endl;

        // Test invalid form creation
        try {
            Form invalidForm("Invalid", 0, 30);
        } catch (std::exception& e) {
            std::cout << "\nException caught: " << e.what() << std::endl;
        }

        try {
            Form invalidForm("Invalid", 151, 30);
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test with a high-grade bureaucrat
        Bureaucrat boss("Boss", 1);
        std::cout << "\nTesting with high-grade bureaucrat:" << std::endl;
        boss.signForm(form2);  // Should succeed (grade 1 < 40)

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
} 