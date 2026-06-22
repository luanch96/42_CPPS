/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:51:53 by luis              #+#    #+#             */
/*   Updated: 2025/06/12 11:52:00 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    typedef AForm* (Intern::*FormCreator)(const std::string&);
    
    struct FormType {
        const char* name;
        FormCreator creator;
    };

    const FormType formTypes[] = {
        {"shrubbery creation", &Intern::createShrubberyForm},
        {"robotomy request", &Intern::createRobotomyForm},
        {"presidential pardon", &Intern::createPresidentialForm}
    };

    for (size_t i = 0; i < sizeof(formTypes) / sizeof(formTypes[0]); ++i) {
        if (formName == formTypes[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formTypes[i].creator)(target);
        }
    }

    std::cout << "Error: Form type \"" << formName << "\" does not exist" << std::endl;
    return NULL;
} 