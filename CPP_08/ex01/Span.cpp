/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:34:39 by luis              #+#    #+#             */
/*   Updated: 2025/09/11 16:52:12 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    return sorted.back() - sorted.front();
}

unsigned int Span::getMaxSize() const {
    return _maxSize;
}

unsigned int Span::getCurrentSize() const {
    return _numbers.size();
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "Cannot calculate span: need at least 2 numbers";
}

 