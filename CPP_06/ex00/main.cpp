/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:50:45 by luis              #+#    #+#             */
/*   Updated: 2025/08/15 12:42:57 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cout << "Examples:" << std::endl;
        std::cout << "  " << argv[0] << " 'a'" << std::endl;
        std::cout << "  " << argv[0] << " 42" << std::endl;
        std::cout << "  " << argv[0] << " 42.0f" << std::endl;
        std::cout << "  " << argv[0] << " 42.0" << std::endl;
        std::cout << "  " << argv[0] << " nan" << std::endl;
        std::cout << "  " << argv[0] << " +inf" << std::endl;
        return 1;
    }

    std::string literal = argv[1];
    ScalarConverter::convert(literal);

    return 0;
} 