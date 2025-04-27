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
#define SKILLS_SETS_PATH "civ2-ordered.txt"

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

std::vector<std::vector<Skill> > buildSets(const std::vector<Skill> &skillList) {

    

}

void writeSkillSets(const std::vector<std::vector<Skill> > &skillSets, const std::string &path) {

    std::ofstream outputFile(path);
    int number = 0;
    for (std::vector<Skill> skillSet : skillSets) {
        outputFile << "SET " << number << std::endl;
        for (Skill skill : skillSet) {
            outputFile << skill << std::endl;
        }
        outputFile << std::endl;
    }

}

int main() {
    std::vector<Skill> skillList = readSkillsFromCSV(SKILLS_PATH);
    // std::vector<std::vector<Skill> > skillSets = buildSets(skillList);
    std::vector<std::vector<Skill> > skillSets = {skillList};
    writeSkillSets(skillSets, SKILLS_SETS_PATH);

    return 0;
}
