/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisanch <luisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:17:16 by luisanch          #+#    #+#             */
/*   Updated: 2025/09/16 11:03:27 by luisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    for (size_t i = 0; i < str.length(); i++) {
        if (i == 0 && str[i] == '-' && str.length() > 1) continue;
        if (str[i] < '0' || str[i] > '9') return false;
    }
    
    long num = std::atol(str.c_str());
    return num > 0 && num <= 2147483647;
}

void PmergeMe::parseInput(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (!isValidNumber(argv[i])) {
            throw std::runtime_error("Invalid number: " + std::string(argv[i]));
        }
        int num = std::atoi(argv[i]);
        _vector.push_back(num);
        _deque.push_back(num);
    }
}

void PmergeMe::displaySequence(const std::string& prefix, const std::vector<int>& seq) {
    std::cout << prefix;
    for (size_t i = 0; i < seq.size(); i++) {
        std::cout << seq[i];
        if (i < seq.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displaySequence(const std::string& prefix, const std::deque<int>& seq) {
    std::cout << prefix;
    for (size_t i = 0; i < seq.size(); i++) {
        std::cout << seq[i];
        if (i < seq.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

double PmergeMe::getTime() {
    clock_t start = clock();
    return (double)(start) / CLOCKS_PER_SEC * 100;
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    
    if (n <= 10) {
        insertionSortVector(arr, 0, n - 1);
        return;
    }
    
    int mid = n / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    
    mergeInsertSortVector(left);
    mergeInsertSortVector(right);
    
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::sortVector() {
    mergeInsertSortVector(_vector);
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::deque<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;
    
    if (n <= 10) {
        insertionSortDeque(arr, 0, n - 1);
        return;
    }
    
    int mid = n / 2;
    std::deque<int> left(arr.begin(), arr.begin() + mid);
    std::deque<int> right(arr.begin() + mid, arr.end());
    
    mergeInsertSortDeque(left);
    mergeInsertSortDeque(right);
    
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void PmergeMe::sortDeque() {
    mergeInsertSortDeque(_deque);
}

void PmergeMe::process(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::runtime_error("No arguments provided");
    }
    
    parseInput(argc, argv);
    
    displaySequence("Before: ", _vector);

    double startTime = getTime();
    sortVector();
    double vectorTime = getTime() - startTime;
    
    displaySequence("After: ", _vector);
    
    startTime = getTime();
    sortDeque();
    double dequeTime = getTime() - startTime;
    
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
} 