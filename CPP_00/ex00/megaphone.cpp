/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:55:18 by luis              #+#    #+#             */
/*   Updated: 2025/04/15 23:29:22 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for(int a = 1; a < argc; a++)
        {
            for(int b = 0; argv[a][b] != '\0'; b++)
            {
                std::cout << (char)std::toupper(argv[a][b]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
