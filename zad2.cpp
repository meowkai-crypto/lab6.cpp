#include <iostream>
#include <vector>
#include <set>
#include <map>

int main() {
    std::vector<int> numbers = {1, 2, 3, 2, 4, 5, 1, 6, 3, 7};

    std::map<int, int> counts;
    for (int num : numbers) {
        counts[num]++;
    }

    std::cout << "Дубликаты: ";
    for (const auto & [num, count] : counts) {
        if (count > 1) {
            std::cout << num << " ";
        }
    }
    std::cout << "\n";

    std::set<int> seen;
    std::set<int> duplicates;
    for (int num : numbers) {
        if (seen.count(num)) {
            duplicates.insert(num);
        }
        seen.insert(num);
    }

    std::cout << "Дубликаты (set): ";
    for (int num : duplicates) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}