#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>

int main() {
    std::vector<std::tuple<std::string, int, double>> students = {
        {"Иван", 25, 4.5},
        {"Мария", 22, 4.8},
        {"Пётр", 30, 4.2},
        {"Анна", 20, 4.9}
    };

    auto oldest = *std::max_element(students.begin(), students.end(),
        [](const auto& a, const auto& b) {
            return std::get<1>(a) < std::get<1>(b);
        });
    std::cout << "Самый старший: " << std::get<0>(oldest) << ", " << std::get<1>(oldest) << " лет\n";

    auto best = *std::max_element(students.begin(), students.end(),
        [](const auto& a, const auto& b) {
            return std::get<2>(a) < std::get<2>(b);
        });
    std::cout << "Лучший студент: " << std::get<0>(best) << ", балл " << std::get<2>(best) << "\n";

    int total_age = std::accumulate(students.begin(), students.end(), 0,
        [](int sum, const auto& student) {
            return sum + std::get<1>(student);
        });
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Средний возраст: " << static_cast<double>(total_age) / students.size() << "\n";

    std::sort(students.begin(), students.end(),
        [](const auto& a, const auto& b) {
            return std::get<2>(a) > std::get<2>(b);
        });

    std::cout << "\nПо баллу:\n";
    for (const auto& [name, age, gpa] : students) {
        std::cout << name << ": " << gpa << "\n";
    }

    return 0;
}