/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:06 by luis              #+#    #+#             */
/*   Updated: 2025/04/16 22:39:54 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void printline(void);
		void start_info(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkestsecret);
		void printinfo(void);
};

#endif

/*La librería <iomanip> en C++ es una biblioteca de manipulación de entrada/salida que proporciona varias funciones para controlar el formato de la salida. En tu código, se utiliza principalmente para formatear la salida de texto en la consola. Aquí están los principales usos que se le dan en tu código:
std::setw(): Esta función se usa para establecer el ancho del campo de salida. En tu código, se usa en la función showlist() para asegurar que cada columna tenga un ancho consistente:*/

//std::cout << "|" << std::setw(10) << (i + 1) << "|";

/*En este caso, (i + 1) es el número de la fila que se está mostrando. La función setw(10) asegura que este número ocupe exactamente 10 caracteres de ancho, lo que hace que todas las filas tengan el mismo ancho.
La librería <iomanip> es particularmente útil cuando necesitas:
Alinear texto en columnas
Controlar el ancho de los campos de salida
Formatear números con precisión específica
Controlar el relleno de espacios
Formatear la salida de manera consistente y profesional*/