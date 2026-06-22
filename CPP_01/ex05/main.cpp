/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:59:48 by luis              #+#    #+#             */
/*   Updated: 2025/04/28 18:59:56 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;
    
    // Probar todos los niveles de queja
    std::cout << "=== DEBUG level ===" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\n=== INFO level ===" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\n=== WARNING level ===" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\n=== ERROR level ===" << std::endl;
    harl.complain("ERROR");
    
    return 0;
}
