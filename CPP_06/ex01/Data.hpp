/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:51:46 by luis              #+#    #+#             */
/*   Updated: 2025/08/15 11:51:52 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int         number;
    std::string text;
    double      value;
    
    Data();
    Data(int n, const std::string& t, double v);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();
};

#endif 