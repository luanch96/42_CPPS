/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:17:22 by luisanch          #+#    #+#             */
/*   Updated: 2025/09/15 14:17:23 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    
    void sortVector();
    void mergeInsertSortVector(std::vector<int>& arr);
    void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    void insertionSortVector(std::vector<int>& arr, int left, int right);
    
    void sortDeque();
    void mergeInsertSortDeque(std::deque<int>& arr);
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    void insertionSortDeque(std::deque<int>& arr, int left, int right);
    
    bool isValidNumber(const std::string& str);
    void parseInput(int argc, char* argv[]);
    void displaySequence(const std::string& prefix, const std::vector<int>& seq);
    void displaySequence(const std::string& prefix, const std::deque<int>& seq);
    double getTime();

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void process(int argc, char* argv[]);
};

#endif 