/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:42:59 by luisanch          #+#    #+#             */
/*   Updated: 2025/05/13 18:37:14 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* _brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    virtual ~Cat();
    void makeSound() const;
    void setIdea(int idx, const std::string& idea);
    std::string getIdea(int idx) const;
};

#endif 