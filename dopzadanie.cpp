#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Защита от переполнения

        if (arr[mid] == target) {
            return mid; // Нашли элемент, возвращаем его индекс
        }
        if (arr[mid] < target) {
            left = mid + 1; // Ищем в правой половине
        } else {
            right = mid - 1; // Ищем в левой половине
        }
    }
    return -1; // Элемент не найден
}

int main() {
    // ВАЖНО: Массив должен быть отсортирован!
    std::vector<int> numbers = {1, 3, 5, 7, 9, 11, 15};
    int target = 7;

    int result = binarySearch(numbers, target);

    if (result != -1) {
        std::cout << "Элемент " << target << " найден по индексу: " << result << "\n";
    } else {
        std::cout << "Элемент " << target << " не найден.\n";
    }

    return 0;
}