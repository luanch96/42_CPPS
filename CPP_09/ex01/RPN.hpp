/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:16:45 by luisanch          #+#    #+#             */
/*   Updated: 2025/09/15 14:16:46 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;
    
    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    void performOperation(const std::string& op);
    int stringToInt(const std::string& str);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int evaluate(const std::string& expression);
};

#endif 