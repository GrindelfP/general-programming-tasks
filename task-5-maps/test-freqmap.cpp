/*

    Task 5. Frequency dictionary.
    Test file.
    Created by GrindelfP on 2024-04-27.

*/

#include <iostream>
#include <fstream>
#include "freqmap.h"

#define PATH_TO_TEXT "text"

int main() {
    std::ifstream inputFile(PATH_TO_TEXT);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << PATH_TO_TEXT << std::endl;
        return 1;
    }

    std::string fileContent;
    std::string line;
    while (std::getline(inputFile, line)) {
        fileContent += line;
        fileContent += " "; // Add space to separate words across lines
    }
    inputFile.close();

    std::unordered_map<std::string, int> frequencyMap = getWordFrequency(fileContent);

    std::cout << "Word Frequency in 'text.txt':" << std::endl;
    for (const auto& pair : frequencyMap) {
        std::cout << "\"" << pair.first << "\": " << pair.second << std::endl;
    }

    return 0;
}
