/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:42:36 by luis              #+#    #+#             */
/*   Updated: 2025/04/22 13:58:54 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	public:
			void	complain(std::string level);
			enum LogLevel {
				DEBUG,
				INFO,
				WARNING,
				ERROR,
				INVALID
			};
			LogLevel getLevelFromString(std::string level);
	private:
			void	_debug();
			void	_info();
			void	_warning();
			void	_error();
};

#endif