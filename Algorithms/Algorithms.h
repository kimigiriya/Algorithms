#pragma once

#include <iostream>
#include <fstream>
#include <locale.h>
#include <locale>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <cstring>
#include <string>
#include <codecvt>

template<typename T>
std::vector<T> ElementsFromFile(const std::string& nameOfFile)
{
    std::ifstream File(nameOfFile, std::ios::in);
    std::vector<T> elements;
    if (File.is_open()) {
        File.imbue(std::locale("rus_rus.1251"));
        T num;
        while (File >> num) {
            elements.emplace_back(num);
        }
        if (File.fail() and !File.eof()) {
            throw std::runtime_error("Ошибка чтения из файла " + nameOfFile);
        }
    }
    else {
        throw std::runtime_error ("Ошибка открытия файла " + nameOfFile);
    }
    File.close();
    return elements;
}

template<typename T>
void Printv(const std::vector<T>& elements)
{
    std::locale loc("ru_RU.UTF-8");
    std::cout.imbue(loc);
    for (const T& value : elements)
        std::cout << value << " ";
    std::cout << "\n";
}

template<typename T>
void PositionOfElements(const std::vector<T>& elements, T n)
{
    auto pseudo = elements.begin();
    while (pseudo != elements.end()) {
        pseudo = std::find(pseudo, elements.end(), n);
        if (pseudo != elements.end()) {
            std::cout << std::distance(elements.begin(), pseudo) << " ";
            pseudo++;
        }
        else {
            break;
        }
    }
    std::cout << "\n";
}

template<typename T>
int EvenElements(const std::vector<T>& elements)
{
    return std::count_if(
        elements.begin(),
        elements.end(),
        [](int x) { return x % 2 == 0; });
}

template <>
int EvenElements<std::string>(const std::vector<std::string>& elements) {
    throw std::invalid_argument("Нельзя проверять четность строк");
}

template<typename T>
int OddElements(const std::vector<T>& elements)
{
    return std::count_if(
        elements.begin(),
        elements.end(),
        [](int x) { return x % 2 != 0; });
}

template <>
int OddElements<std::string>(const std::vector<std::string>& elements) {
    throw std::invalid_argument("Нельзя проверять нечетность строк");
}

template<typename T>
void PositionOfEvenElements(const std::vector<T>& elements)
{
    auto pseudo = elements.begin();
    while (pseudo != elements.end()) {
        pseudo = std::find_if(pseudo, elements.end(), [](const T& value) { return value % 2 == 0; });
        if (pseudo != elements.end()) {
            std::cout << std::distance(elements.begin(), pseudo) << " ";
            pseudo++;
        }
        else {
            break;
        }
    }
    std::cout << "\n";
}

template <>
void PositionOfEvenElements<std::string>(const std::vector<std::string>& elements) {
    throw std::invalid_argument("Нельзя проверять четность строк");
}

template<typename T>
void PositionOfOddElements(const std::vector<T>& elements)
{
    auto pseudo = elements.begin();
    while (pseudo != elements.end()) {
        pseudo = std::find_if(pseudo, elements.end(), [](const T& value) { return value % 2 != 0; });
        if (pseudo != elements.end()) {
            std::cout << std::distance(elements.begin(), pseudo) << " ";
            pseudo++;
        }
        else {
            break;
        }
    }
    std::cout << "\n";
}

template <>
void PositionOfOddElements<std::string>(const std::vector<std::string>& elements) {
    throw std::invalid_argument("Нельзя проверять нечетность строк");
}

template<typename T>
int SumOfEvenElements(const std::vector<T>& elements)
{
    int sum = 0;
    for (int i = 0; i < elements.size(); ++i) {
        if (elements[i] % 2 == 0) {
            sum += elements[i];
        }
    }
    return sum;
}

template <>
int SumOfEvenElements<std::string>(const std::vector<std::string>& elements) {
    throw std::invalid_argument("Нельзя проверять четность строк");
}

template<typename T>
int SumOfOddElements(const std::vector<T>& elements)
{
    int sum = 0;
    for (int i = 0; i < elements.size(); ++i) {
        if (elements[i] % 2 != 0) {
            sum += elements[i];
        }
    }
    return sum;
}

template <>
int SumOfOddElements<std::string>(const std::vector<std::string>& elements) {
    throw std::invalid_argument("Нельзя проверять нечетность строк");
}