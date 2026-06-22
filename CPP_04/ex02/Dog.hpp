/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:43:25 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:37:20 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* _brain;
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();
    void makeSound() const;
    void setIdea(int idx, const std::string& idea);
    std::string getIdea(int idx) const;
};

#endif 