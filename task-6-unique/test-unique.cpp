/*
*
*	Task 6: Unique algotythm. 
*	Created by GrindelfP on 2024-04-27.
*
*/

#include "unique.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iterator> 

// Function to print the contents of a container
template <typename Container>
void printContainer(const Container& c, const std::string& prefix = "") {
    std::cout << prefix;
    for (const auto& element : c) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Test function for the unique function
int main() {
    std::cout << "Testing the unique function:\n\n";

    // 1. Test with a vector of integers (normal case with duplicates)
    std::cout << "Test 1: Vector of integers with duplicates\n";
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> uniqueVec;
    guique::unique(vec.begin(), vec.end(), std::back_inserter(uniqueVec)); // Use back_inserter
    printContainer(vec, "Original vector: ");
    printContainer(uniqueVec, "Unique vector: ");
    std::cout << "\n";

    // 2. Test with a list of strings (normal case with duplicates, different container)
    std::cout << "Test 2: List of strings with duplicates\n";
    std::list<std::string> list = {"apple", "banana", "apple", "cherry", "banana"};
    std::list<std::string> uniqueList;
    guique::unique(list.begin(), list.end(), std::back_inserter(uniqueList));
    printContainer(list, "Original list: ");
    printContainer(uniqueList, "Unique list: ");
    std::cout << "\n";

    // 3. Test with a vector of integers (no duplicates)
    std::cout << "Test 3: Vector of integers with no duplicates\n";
    std::vector<int> vecNoDup = {1, 2, 3, 4, 5};
    std::vector<int> uniqueVecNoDup;
    guique::unique(vecNoDup.begin(), vecNoDup.end(), std::back_inserter(uniqueVecNoDup));
    printContainer(vecNoDup, "Original vector: ");
    printContainer(uniqueVecNoDup, "Unique vector: ");
    std::cout << "\n";

    // 4. Test with an empty vector (edge case)
    std::cout << "Test 4: Empty vector\n";
    std::vector<int> emptyVec;
    std::vector<int> uniqueEmptyVec;
    guique::unique(emptyVec.begin(), emptyVec.end(), std::back_inserter(uniqueEmptyVec));
    printContainer(emptyVec, "Original vector: ");
    printContainer(uniqueEmptyVec, "Unique vector: ");
    std::cout << "\n";

     // 5. Test with a vector where all elements are the same (edge case)
    std::cout << "Test 5: Vector with all same elements\n";
    std::vector<int> sameVec = {5, 5, 5, 5, 5};
    std::vector<int> uniqueSameVec;
    guique::unique(sameVec.begin(), sameVec.end(), std::back_inserter(uniqueSameVec));
    printContainer(sameVec, "Original vector: ");
    printContainer(uniqueSameVec, "Unique vector: ");
    std::cout << "\n";

    // 6. Test with a vector, with duplicates at the beginning and end
    std::cout << "Test 6: Vector with duplicates at start and end\n";
    std::vector<int> duplicateStartEndVec = {1, 1, 2, 3, 4, 4, 5, 5};
    std::vector<int> uniqueDuplicateStartEndVec;
    guique::unique(duplicateStartEndVec.begin(), duplicateStartEndVec.end(), std::back_inserter(uniqueDuplicateStartEndVec));
    printContainer(duplicateStartEndVec, "Original vector: ");
    printContainer(uniqueDuplicateStartEndVec, "Unique vector: ");
    std::cout << "\n";

    return 0;
}
