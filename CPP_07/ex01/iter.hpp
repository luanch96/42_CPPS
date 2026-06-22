/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:04:10 by luis              #+#    #+#             */
/*   Updated: 2025/08/16 17:04:14 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T* array, size_t length, void (*f)(T&)) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

template<typename T>
void iter(const T* array, size_t length, void (*f)(const T&)) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif 