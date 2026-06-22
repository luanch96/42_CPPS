/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:15:54 by luisanch          #+#    #+#             */
/*   Updated: 2025/09/16 11:05:10 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open data.csv" << std::endl;
        return;
    }
    
    std::string line;

    std::getline(file, line);
    
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string valueStr = line.substr(commaPos + 1);
            
            if (isValidDate(date)) {
                float value = std::atof(valueStr.c_str());
                _database[date] = value;
            }
        }
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 2009 || year > 2024) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && day > 29) return false;
        if (!isLeap && day > 28) return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) {
    float val = std::atof(value.c_str());
    
    if (val < 0) return false;
    if (val > 1000) return false;
    
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    if (_database.empty()) return "";
    
    std::map<std::string, float>::iterator it = _database.lower_bound(date);
    
    if (it == _database.begin()) {
        return it->first;
    }
    
    if (it == _database.end() || it->first != date) {
        --it;
    }
    
    return it->first;
}

float BitcoinExchange::getExchangeRate(const std::string& date) {
    std::string closestDate = findClosestDate(date);
    if (closestDate.empty()) return 0.0f;
    
    return _database[closestDate];
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
 
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipePos);
        std::string value = line.substr(pipePos + 3);
        
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        if (!isValidValue(value)) {
            float val = std::atof(value.c_str());
            if (val < 0) {
                std::cout << "Error: not a positive number." << std::endl;
            } else if (val > 1000) {
                std::cout << "Error: too large a number." << std::endl;
            } else {
                std::cout << "Error: bad input => " << line << std::endl;
            }
            continue;
        }
        
        float bitcoinValue = std::atof(value.c_str());
        float exchangeRate = getExchangeRate(date);
        float result = bitcoinValue * exchangeRate;
        
        std::cout << date << " => " << bitcoinValue << " = " << result << std::endl;
    }
    file.close();
} 