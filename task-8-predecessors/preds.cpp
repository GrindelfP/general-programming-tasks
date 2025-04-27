/*

    Task 8 (bonus). Find predecessors and build sets.
    Source code file.
    Created by GrindelfP on 2024-04-27.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

/**
 * @brief Splits a string into tokens based on a delimiter.
 * 
 * @param s Input string to split.
 * @param delimiter Character to split the string by.
 * @return std::vector<std::string> Vector containing the split parts.
 */
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

/**
 * @brief Main function that reads Civilization 2 skills from a CSV file,
 * sorts them based on their prerequisites into sets A, B, C, etc.,
 * and writes the result into an output file.
 * 
 * @return int Exit code (0 = success, non-zero = error).
 */
int main() {
    std::ifstream file("civ2.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open civ2.csv" << std::endl;
        return 1;
    }

    std::map<std::string, std::vector<std::string>> prerequisites; ///< Maps each skill to its prerequisites.
    std::set<std::string> all_skills; ///< Set of all skills.

    // Read the CSV file line by line
    std::string line;
    while (std::getline(file, line)) {
        auto parts = split(line, ',');
        if (parts.empty()) continue;

        std::string skill = parts[0];
        all_skills.insert(skill);

        std::vector<std::string> pre;
        for (std::size_t i = 1; i < parts.size(); ++i) {
            if (!parts[i].empty()) {
                pre.push_back(parts[i]);
            }
        }
        prerequisites[skill] = pre;
    }
    file.close();

    // Layers of skills: Set A, Set B, etc.
    std::vector<std::vector<std::string>> layers;
    std::set<std::string> learned; ///< Skills already assigned to a layer.

    // Process skills layer by layer
    while (!all_skills.empty()) {
        std::vector<std::string> current_layer;

        for (auto it = all_skills.begin(); it != all_skills.end(); ) {
            const std::string& skill = *it;
            const std::vector<std::string>& pre = prerequisites[skill];

            bool can_learn = true;
            for (const std::string& p : pre) {
                if (learned.find(p) == learned.end()) {
                    can_learn = false;
                    break;
                }
            }

            if (can_learn) {
                current_layer.push_back(skill);
                it = all_skills.erase(it);
            } else {
                ++it;
            }
        }

        if (current_layer.empty()) {
            std::cerr << "Error: Cyclic or missing dependency detected!" << std::endl;
            return 2;
        }

        for (const std::string& skill : current_layer) {
            learned.insert(skill);
        }

        layers.push_back(current_layer);
    }

    // Write the sorted skills to an output file
    std::ofstream output("civ2_sorted.txt");
    if (!output.is_open()) {
        std::cerr << "Failed to create output file" << std::endl;
        return 3;
    }

    char setName = 'A';
    for (const auto& layer : layers) {
        output << "Set " << setName++ << ":\n";
        for (const std::string& skill : layer) {
            output << skill << "\n";
        }
        output << "\n";
    }
    output.close();

    std::cout << "Skills sorted and saved to civ2_sorted.txt" << std::endl;
    return 0;
}
