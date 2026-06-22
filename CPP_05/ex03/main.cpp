/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:52:19 by luis              #+#    #+#             */
/*   Updated: 2025/06/12 11:52:22 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        AForm* form;

        // Test creating different forms
        std::cout << "\nTesting form creation:" << std::endl;
        
        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }

        form = someRandomIntern.makeForm("presidential pardon", "Arthur");
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }

        // Test invalid form
        form = someRandomIntern.makeForm("invalid form", "target");
        if (form) {
            delete form;
        }

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
} 