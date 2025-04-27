/*

    Task 5. Frequency dictionary.
    Header file containing getWordFrequency() function.
    Created by GrindelfP on 2024-04-27.

*/
#ifndef freqmap_h
#define freqmap_h

#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

std::unordered_map<std::string, int> getWordFrequency(const std::string& text) {
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

    return wordFrequency;
}

#endif // freqmap_h
