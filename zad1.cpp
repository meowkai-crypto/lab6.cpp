#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <unordered_set>

int main() {
    int n;
    std::cout << "Введите N: ";
    std::cin >> n;

    // Инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    // 1. Создание списка
    std::vector<int> numbers(n);
    for (int& x : numbers) {
        x = dist(gen);
    }

    std::cout << "Исходный список: ";
    for (int x : numbers) std::cout << x << " ";
    std::cout << "\n";

    // 2. Сумма, среднее, минимум, максимум
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Сумма: " << sum << "\n";
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Среднее: " << static_cast<double>(sum) / n << "\n";
    
    std::cout << "Минимум: " << *std::min_element(numbers.begin(), numbers.end()) << "\n";
    std::cout << "Максимум: " << *std::max_element(numbers.begin(), numbers.end()) << "\n";

    // 3. Сортировка
    // Создаем копию, чтобы не портить исходный порядок для следующего пункта
    std::vector<int> sorted_numbers = numbers; 
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    
    std::cout << "Отсортированный: ";
    for (int x : sorted_numbers) std::cout << x << " ";
    std::cout << "\n";

    // 4. Удаление дубликатов (сохраняя порядок)
    // Используем unordered_set для отслеживания уникальных элементов
    std::unordered_set<int> seen;
    std::vector<int> unique_numbers;
    
    for (int x : numbers) {
        // Если элемента еще нет в множестве, добавляем его в результат
        if (seen.insert(x).second) {
            unique_numbers.push_back(x);
        }
    }

    std::cout << "Без дубликатов: ";
    for (int x : unique_numbers) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}