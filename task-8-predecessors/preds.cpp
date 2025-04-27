/*

    Task 8 (bonus). Find predecessors and build sets.
    Source code file.
    Created by GrindelfP on 2024-04-27.

*/

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Skill.h"

#define SKILLS_PATH "civ2.csv"

std::vector<Skill> readSkillsFromCSV(const std::string& filename) {
    std::vector<Skill> skills;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return skills;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> row;

        while (std::getline(ss, segment, ',')) {
            row.push_back(segment);
        }

        if (row.size() == 4) {
            skills.emplace_back(row[0], row[1], row[2], row[3]);
        } else {
            std::cerr << "Warning: Skipping invalid row with " << row.size() << " columns: " << line << std::endl;
        }
    }

    file.close();

    return skills;
}

int main() {
    std::vector<Skill> skillList = readSkillsFromCSV(SKILLS_PATH);

    for (const auto& skill : skillList) {
        std::cout << skill.toString() << std::endl;
    }

    // Example of how to create a vector of pairs (name, code)
    std::vector<std::pair<std::string, std::string>> nameCodePairs;
    for (const auto& skill : skillList) {
        nameCodePairs.push_back(skill.pairNameCode());
    }

    std::cout << "\nName-Code Pairs:" << std::endl;
    for (const auto& pair : nameCodePairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }

    return 0;
}
