/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:34:54 by luis              #+#    #+#             */
/*   Updated: 2025/09/11 16:52:49 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    
    ~Span();
    
    Span& operator=(const Span& other);
    
    void addNumber(int number);
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        unsigned int distance = std::distance(begin, end);
        if (_numbers.size() + distance > _maxSize) {
            throw SpanFullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    unsigned int getMaxSize() const;
    unsigned int getCurrentSize() const;
    
    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif 