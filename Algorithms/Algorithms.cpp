#include "Algorithms.h"
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

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 >> null");

	try {
		std::vector<int> prime = ElementsFromFile<int>("PrimeNumbers.txt");
		std::cout << "Исходные элементы:\n";
		Printv(prime);

		int n;
		std::cout << "Введите n: ";
		std::cin >> n;
		int countN = count(prime.begin(), prime.end(), n);
		if (countN > 0) {
			std::cout << "Элемент " << n << " встречается " << countN << " раз" << "\n";
			std::cout << "Позиция элементов " << n << ": ";
			PositionOfElements(prime, n);
		}
		else {
			std::cout << "Элемент " << n << " не найден в файле\n";
		}
        
		int evenCount = EvenElements(prime);
		std::cout << "Количество четных элементов: " << evenCount << "\n";
		int oddCount = OddElements(prime);
		std::cout << "Количество нечетных элементов: " << oddCount << "\n";
		std::cout << "Позиция четных элементов " << n << ": ";
		PositionOfEvenElements(prime);
		std::cout << "Позиция нечетных элементов " << n << ": ";
		PositionOfOddElements(prime);
		int sum = 0;
		if (evenCount > oddCount) {
			std::cout << "Кол-во четный элементов больше, чем нечётных элементов\n";
			sum = SumOfEvenElements(prime);
			printf("Сумма всех чётных элементов: %d\n", sum);
		}
		else {
			std::cout << "Кол-во четный элементов равно или меньше, чем нечётных элементов\n";
			sum = SumOfEvenElements(prime) + SumOfOddElements(prime);
			printf("Сумма всех элементов: %d\n", sum);
		}

		std::vector<int> sorty = prime;
		std::sort(sorty.begin(), sorty.end());
		std::cout << "Отсортирированные элементы:\n";
		Printv(sorty);

		std::cout << "Перестановка первого элемента и последнего элемента\n";
		if (prime.size() > 1) {	
			std::swap(prime.front(), prime.back());
			std::cout << "Переставленные элементы:\n";
			Printv(prime);
		}
		else if (prime.size() == 1) {
			std::cout << "Вектор содержит только один элемент, перестановка невозможна\n";
		}
		else {
			std::cout << "Вектор пуст, перестановка невозможна\n";
		}
	}
	catch (const std::runtime_error& error) {
		std::cerr << error.what() << std::endl;
	}
	catch (const std::invalid_argument& error) {
		std::cerr << "Ошибка: " << error.what() << std::endl;
	}

	return 0;
}
