/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:16:37 by luisanch          #+#    #+#             */
/*   Updated: 2025/09/16 11:08:34 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string& token) {
    if (token.empty()) return false;
    
    for (size_t i = 0; i < token.length(); i++) {
        if (i == 0 && token[i] == '-' && token.length() > 1) continue;
        if (token[i] < '0' || token[i] > '9') return false;
    }
    
    int num = stringToInt(token);
    return num >= 0 && num < 10;
}

int RPN::stringToInt(const std::string& str) {
    return std::atoi(str.c_str());
}

void RPN::performOperation(const std::string& op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Not enough operands for operation");
    }
    
    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();
    
    if (op == "+") {
        _stack.push(a + b);
    } else if (op == "-") {
        _stack.push(a - b);
    } else if (op == "*") {
        _stack.push(a * b);
    } else if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        _stack.push(a / b);
    }
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isNumber(token)) {
            _stack.push(stringToInt(token));
        } else if (isOperator(token)) {
            try {
                performOperation(token);
            } catch (const std::exception& e) {
                throw;
            }
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }
    
    if (_stack.size() != 1) {
        throw std::runtime_error("Invalid expression: wrong number of operands");
    }
    return _stack.top();
} 