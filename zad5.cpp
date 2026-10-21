#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> list1 = {1, 2, 3, 4, 5};
    std::vector<int> list2 = {4, 5, 6, 7, 8};

    std::set<int> set1(list1.begin(), list1.end());
    std::set<int> set2(list2.begin(), list2.end());

    std::set<int> unionSet;
    std::set_union(set1.begin(), set1.end(),
                   set2.begin(), set2.end(),
                   std::inserter(unionSet, unionSet.begin()));

    std::set<int> intersection;
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::inserter(intersection, intersection.begin()));

    std::set<int> difference;
    std::set_difference(set1.begin(), set1.end(),
                        set2.begin(), set2.end(),
                        std::inserter(difference, difference.begin()));

    std::cout << "Объединение: ";
    for (int x : unionSet) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Пересечение: ";
    for (int x : intersection) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Разность: ";
    for (int x : difference) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}