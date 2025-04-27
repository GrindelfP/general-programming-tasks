#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include "container-utils.h"

int main() {
    // Test dremove with a vector of integers
    std::cout << "Test dremove with vector of integers:\n";
    std::vector<int> vec = {1, 2, 3, 4, 2, 5, 2, 6};
    std::cout << "Original vector: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n";

    auto newEnd = dremove(vec.begin(), vec.end(), 2);
    std::cout << "Vector after removing 2: ";
    for (auto it = vec.begin(); it != newEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    vec.erase(newEnd, vec.end()); //erase the "removed" elements
    std::cout << "Vector after erasing: ";
    for (int x : vec) std::cout << x << " ";
    std::cout << "\n\n";

    // Test dremove with a list of strings
    std::cout << "Test dremove with list of strings:\n";
    std::list<std::string> strList = {"apple", "banana", "cherry", "banana", "date"};
    std::cout << "Original list: ";
    for (const auto& str : strList) std::cout << str << " ";
    std::cout << "\n";

    auto newStrEnd = dremove(strList.begin(), strList.end(), std::string("banana"));
    std::cout << "List after removing 'banana': ";
    for (auto it = strList.begin(); it != newStrEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    strList.erase(newStrEnd, strList.end());
    std::cout << "List after erasing: ";
    for (const auto& str : strList) std::cout << str << " ";
    std::cout << "\n\n";

    // Test dremove with an empty vector
    std::cout << "Test dremove with empty vector:\n";
    std::vector<int> emptyVec;
    std::cout << "Original empty vector: ";
    for (int x : emptyVec) std::cout << x << " "; //prints nothing
    std::cout << "\n";
    auto emptyEnd = dremove(emptyVec.begin(), emptyVec.end(), 5);
    std::cout << "Empty vector after removing 5: ";
    for (auto it = emptyVec.begin(); it != emptyEnd; ++it) {
        std::cout << *it << " "; //prints nothing
    }
    std::cout << "\n\n";


    // Test dremoveIf with a vector and a predicate (even numbers)
    std::cout << "Test dremoveIf with vector and predicate (even numbers):\n";
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << "Original vector: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n";

    auto newNumbersEnd = dremoveIf(numbers.begin(), numbers.end(), [](int n){ return n % 2 == 0; });
    std::cout << "Vector after removing even numbers: ";
    for (auto it = numbers.begin(); it != newNumbersEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    numbers.erase(newNumbersEnd, numbers.end());
    std::cout << "Vector after erasing: ";
    for (int num : numbers) std::cout << num << " ";
    std::cout << "\n\n";

    // Test dremoveIf with a list and a predicate (strings longer than 4)
    std::cout << "Test dremoveIf with list and predicate (strings longer than 4):\n";
    std::list<std::string> wordList = {"apple", "banana", "cat", "date", "grape"};
    std::cout << "Original list: ";
    for (const auto& word : wordList) std::cout << word << " ";
    std::cout << "\n";

    auto newWordEnd = dremoveIf(wordList.begin(), wordList.end(), [](const std::string& str){ return str.length() > 4; });
    std::cout << "List after removing strings longer than 4: ";
    for (auto it = wordList.begin(); it != newWordEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    wordList.erase(newWordEnd, wordList.end());
     std::cout << "List after erasing: ";
    for (const auto& word : wordList) std::cout << word << " ";
    std::cout << "\n\n";

    // Test dremoveIf with a vector and a predicate that always returns false (no removal)
     std::cout << "Test dremoveIf with a vector and a predicate that always returns false (no removal):\n";
    std::vector<int> noRemoveVec = {10, 20, 30, 40, 50};
    std::cout << "Original vector: ";
    for (int val : noRemoveVec) std::cout << val << " ";
    std::cout << "\n";

    auto noRemoveEnd = dremoveIf(noRemoveVec.begin(), noRemoveVec.end(), [](int){ return false; });
    std::cout << "Vector after attempting to remove none: ";
    for (auto it = noRemoveVec.begin(); it != noRemoveEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    noRemoveVec.erase(noRemoveEnd, noRemoveVec.end());
    std::cout << "Vector after erasing: ";
    for (int val : noRemoveVec) std::cout << val << " ";
    std::cout << "\n\n";


    // Test transform with a vector and a function (multiply by 2)
    std::cout << "Test transform with vector and function (multiply by 2):\n";
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "Original vector: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";

    auto newNumsEnd = transform(nums.begin(), nums.end(), [](int n){ return n * 2; });
    std::cout << "Vector after multiplying by 2: ";
     for (auto it = nums.begin(); it != newNumsEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    nums.erase(newNumsEnd, nums.end());
    std::cout << "Vector after erasing: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n\n";

    // Test transform with a list and a function (convert to uppercase)
    std::cout << "Test transform with list and function (convert to uppercase):\n";
    std::list<std::string> words = {"apple", "banana", "cherry"};
    std::cout << "Original list: ";
    for (const auto& word : words) std::cout << word << " ";
    std::cout << "\n";

    auto newWordsEnd = transform(words.begin(), words.end(), [](std::string str){
        for (char &c : str) {
            c = std::toupper(c);
        }
        return str;
    });
    std::cout << "List after converting to uppercase: ";
    for (auto it = words.begin(); it != newWordsEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    words.erase(newWordsEnd, words.end());
    std::cout << "List after erasing: ";
    for (const auto& word : words) std::cout << word << " ";
    std::cout << "\n\n";

    // Test transform with an empty vector
    std::cout << "Test transform with an empty vector:\n";
    std::vector<int> emptyTransformVec;
     std::cout << "Original empty vector: ";
    for (int val : emptyTransformVec) std::cout << val << " "; //prints nothing
    std::cout << "\n";

    auto emptyTransformEnd = transform(emptyTransformVec.begin(), emptyTransformVec.end(), [](int n){ return n * 3; });
    std::cout << "Vector after transforming empty vector: ";
    for (auto it = emptyTransformVec.begin(); it != emptyTransformEnd; ++it) {
        std::cout << *it << " "; //prints nothing
    }
    std::cout << "\n\n";

    return 0;
}
