/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:04:43 by luis              #+#    #+#             */
/*   Updated: 2025/08/16 17:04:52 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template<typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    Array() : _array(NULL), _size(0) {}

    Array(unsigned int n) : _size(n) {
        if (n == 0) {
            _array = NULL;
        } else {
            _array = new T[n](); 
        }
    }

    Array(const Array& other) : _size(other._size) {
        if (_size == 0) {
            _array = NULL;
        } else {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _array;
            _size = other._size;
            if (_size == 0) {
                _array = NULL;
            } else {
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _array[i] = other._array[i];
                }
            }
        }
        return *this;
    }

    ~Array() {
        delete[] _array;
    }

    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::exception();
        }
        return _array[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::exception();
        }
        return _array[index];
    }


    unsigned int size() const {
        return _size;
    }
};

#endif 