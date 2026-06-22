/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:51:08 by luis              #+#    #+#             */
/*   Updated: 2025/08/15 11:58:34 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& literal) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        return true;
    }
    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        return true;
    }
    return false;
}

static bool isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-') start = 1;
    if (start >= literal.length()) return false;
    
    for (size_t i = start; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    return true;
}

static bool isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
    
    if (literal.empty() || literal[literal.length() - 1] != 'f') return false;
    
    std::string withoutF = literal.substr(0, literal.length() - 1);
    if (withoutF.empty()) return false;
    
    size_t start = 0;
    if (withoutF[0] == '+' || withoutF[0] == '-') start = 1;
    if (start >= withoutF.length()) return false;
    
    bool hasDot = false;
    for (size_t i = start; i < withoutF.length(); i++) {
        if (withoutF[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(withoutF[i])) {
            return false;
        }
    }
    return hasDot;
}

static bool isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
    
    if (literal.empty()) return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-') start = 1;
    if (start >= literal.length()) return false;
    
    bool hasDot = false;
    for (size_t i = start; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    return hasDot;
}

static bool isFinite(double value) {
    return value != std::numeric_limits<double>::infinity() && 
           value != -std::numeric_limits<double>::infinity() && 
           value == value;
}

static void printChar(char c) {
    if (std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

static void printInt(int i) {
    std::cout << "int: " << i << std::endl;
}

static void printFloat(float f) {
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double d) {
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: Empty literal" << std::endl;
        return;
    }

    if (isChar(literal)) {
        char c;
        if (literal.length() == 3) {
            c = literal[1];
        } else {
            c = literal[0];
        }
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
        return;
    }

    if (isInt(literal)) {
        long longValue = std::atol(literal.c_str());
        if (longValue > std::numeric_limits<int>::max() || 
            longValue < std::numeric_limits<int>::min()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        
        int i = static_cast<int>(longValue);
        if (i >= 0 && i <= 127) {
            char c = static_cast<char>(i);
            if (std::isprint(c)) {
                std::cout << "char: '" << c << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
        return;
    }

    if (isFloat(literal)) {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (literal == "-inff") {
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
            } else if (literal == "+inff") {
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
            } else {
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            }
            return;
        }
        
        std::string withoutF = literal.substr(0, literal.length() - 1);
        double doubleValue = std::atof(withoutF.c_str());
        float f = static_cast<float>(doubleValue);
        
        if (doubleValue >= 0 && doubleValue <= 127 && isFinite(doubleValue)) {
            printChar(static_cast<char>(doubleValue));
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        
        if (doubleValue > std::numeric_limits<int>::max() || 
            doubleValue < std::numeric_limits<int>::min() || 
            !isFinite(doubleValue)) {
            std::cout << "int: impossible" << std::endl;
        } else {
            printInt(static_cast<int>(doubleValue));
        }
        
        printFloat(f);
        printDouble(doubleValue);
        return;
    }

    if (isDouble(literal)) {
        if (literal == "-inf" || literal == "+inf" || literal == "nan") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (literal == "-inf") {
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
            } else if (literal == "+inf") {
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
            } else {
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            }
            return;
        }
        
        double d = std::atof(literal.c_str());
        
        if (d >= 0 && d <= 127 && isFinite(d)) {
            printChar(static_cast<char>(d));
        } else {
            std::cout << "char: impossible" << std::endl;
        }
        
        if (d > std::numeric_limits<int>::max() || 
            d < std::numeric_limits<int>::min() || 
            !isFinite(d)) {
            std::cout << "int: impossible" << std::endl;
        } else {
            printInt(static_cast<int>(d));
        }
        
        printFloat(static_cast<float>(d));
        printDouble(d);
        return;
    }

    std::cout << "Error: Invalid literal format" << std::endl;
} 