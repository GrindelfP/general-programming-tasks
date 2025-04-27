/*

    Task 5. Frequency dictionary.
    Header file containing getWordFrequency() function.
    Created by GrindelfP on 2024-04-27.

*/
#ifndef freqmap_h
#define freqmap_h

#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

/**
 * @brief Calculates the frequency of each word in a given text and returns an ordered map.
 *
 * This function takes a string of text as input, converts all words to lowercase,
 * removes punctuation, counts the occurrences of each unique word, and then
 * returns the word frequencies as a map ordered by frequency in descending order.
 *
 * @param text The input string of text.
 * @return A map where keys are lowercase words and values are their frequencies,
 * ordered from the most frequent word to the least frequent.
 */
std::map<std::string, int, std::function<bool(const int&, const int&)>> getWordFrequency(const std::string& text) {
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

    // Custom comparator to order by frequency (descending)
    auto cmp = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
    };

    // Create a vector of pairs from the unordered map
    std::vector<std::pair<std::string, int>> sortedVector(wordFrequency.begin(), wordFrequency.end());

    // Sort the vector using the custom comparator
    std::sort(sortedVector.begin(), sortedVector.end(), cmp);

    // Create an ordered map from the sorted vector
    std::map<std::string, int, std::function<bool(const int&, const int&)>> orderedFrequencyMap;
    for (const auto& pair : sortedVector) {
        orderedFrequencyMap[pair.first] = pair.second;
    }

    return orderedFrequencyMap;
}

#endif // freqmap_h
