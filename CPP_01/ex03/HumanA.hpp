/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:28:00 by luis              #+#    #+#             */
/*   Updated: 2025/04/22 13:54:02 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
    private:
        std::string name;
        Weapon& weapon;  // Referencia al arma
    
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack() const;
};

#endif

