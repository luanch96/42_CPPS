/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:51:39 by luis              #+#    #+#             */
/*   Updated: 2025/08/15 11:51:42 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : number(0), text(""), value(0.0) {}

Data::Data(int n, const std::string& t, double v) : number(n), text(t), value(v) {}

Data::Data(const Data& other) : number(other.number), text(other.text), value(other.value) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        number = other.number;
        text = other.text;
        value = other.value;
    }
    return *this;
}

Data::~Data() {} 