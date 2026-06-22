/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:49:20 by luis              #+#    #+#             */
/*   Updated: 2025/06/12 11:49:22 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);
        Bureaucrat manager("Manager", 50);

        // Create forms
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur");

        std::cout << "\nTesting form signing and execution:" << std::endl;
        
        // Test with boss (grade 1)
        std::cout << "\nBoss (grade 1) trying to sign and execute forms:" << std::endl;
        boss.signForm(shrubbery);
        boss.executeForm(shrubbery);
        
        boss.signForm(robotomy);
        boss.executeForm(robotomy);
        
        boss.signForm(pardon);
        boss.executeForm(pardon);

        // Test with manager (grade 50)
        std::cout << "\nManager (grade 50) trying to sign and execute forms:" << std::endl;
        manager.signForm(shrubbery);
        manager.executeForm(shrubbery);
        
        manager.signForm(robotomy);
        manager.executeForm(robotomy);
        
        manager.signForm(pardon);
        manager.executeForm(pardon);

        // Test with intern (grade 150)
        std::cout << "\nIntern (grade 150) trying to sign and execute forms:" << std::endl;
        intern.signForm(shrubbery);
        intern.executeForm(shrubbery);
        
        intern.signForm(robotomy);
        intern.executeForm(robotomy);
        
        intern.signForm(pardon);
        intern.executeForm(pardon);

        // Test form copy and assignment
        std::cout << "\nTesting form copy and assignment:" << std::endl;
        ShrubberyCreationForm shrubbery2(shrubbery);
        std::cout << "Copied shrubbery form: " << shrubbery2 << std::endl;

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
} 