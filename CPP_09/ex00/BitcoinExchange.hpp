/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:16:01 by luisanch          #+#    #+#             */
/*   Updated: 2025/09/15 14:16:02 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _database;
    
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
    std::string findClosestDate(const std::string& date);
    float getExchangeRate(const std::string& date);
    void loadDatabase();

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void processInputFile(const std::string& filename);
};

#endif 