/*

    Task 5. Frequency dictionary.
    Header file containing getWordFrequency() function.
    Created by GrindelfP on 2024-04-27.

*/
#ifndef freqmap_h
#define freqmap_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include "freqmap.h" // Include the header file

/**
 * @brief Calculates the frequency of each word in a given text and returns an ordered vector of pairs.
 *
 * This function takes a string of text as input, converts all words to lowercase,
 * removes punctuation, counts the occurrences of each unique word, and then
 * returns the word frequencies as a vector of pairs ordered by frequency in descending order.
 *
 * @param text The input string of text.
 * @return A vector of pairs where the first element is the lowercase word and the
 * second element is its frequency, ordered from the most frequent word
 * to the least frequent.
 */
std::vector<std::pair<std::string, int>> getWordFrequency(const std::string& text) {
    std::unordered_map<std::string, int> wordFrequency;
    std::stringstream ss(text);
    std::string word;

    while (ss >> word) {
        // Convert to lowercase
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Remove punctuation from the end of the word
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());

        // Increment the frequency count
        if (!word.empty()) {
            wordFrequency[word]++;
        }
    }

    // Create a vector of pairs from the unordered map
    std::vector<std::pair<std::string, int>> sortedVector(wordFrequency.begin(), wordFrequency.end());

    // Custom comparator to order by frequency (descending)
    std::sort(sortedVector.begin(), sortedVector.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
    });

    return sortedVector;
}

#endif // freqmap_h
