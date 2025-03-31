/*
*
*	Task 4: Segments. 
*	Created by GrindelfP on 2024-03-30.
*
*/

#include "segments.h"
#include <iostream>

/**
* @brief Main function.
* 
* Main function of the program. Receives user input
* of segments' vertexes. Calls functions to build
* broiken lines out of the vertexes,
*
* @param argc number of main function parameters.
* @param argv function parameters.
*
* @return 0 if worked as required. 
*/
int main(int argc, char** argv) {

	std::vector<std::pair<int, int> > segments;
	std::vector<std::vector<int> > brokenLine;
	int 
		numberOfSegments,
		i,
		j,
		a, 
		b;
	
	// =======================
	// SEGMENTS INITIALIZATION
	// =======================
	std::cout << "Please enter number of segments you want to create: ";
	std::cin >> numberOfSegments;

	for (i = 0; i < numberOfSegments; ++i) {
		std::cout << "Please enter the vertexes of a segment" 
				<< " and press ENTER after each of two vertexes:\n";
		std::cin >> a;
		std::cin >> b;
		segments.push_back(std::make_pair(a, b));
	}
	
	// =====================
	// BUILDING BROKEN LINES
	// =====================
	brokenLine = buildBrokenLine(segments);
		

	// ==================
	// OUTPUT BROKEN LINE
	// ==================
	if (brokenLine.size()  == 0) std::cout << "There is no broken lines built!\n";
	else {
		for (i = 0; i < brokenLine.size(); ++i) {
			std::cout << brokenLine.size() << std::endl;
			std::cout << "Broken line "<< i+1 <<": ";
			for (j = 0; j < brokenLine[i].size(); ++j) {
				std::cout << brokenLine[i][j];
				if (j != brokenLine[i].size() - 1) std::cout << ", ";
			}
			std::cout << std::endl;
		}
	}
	
	return 0;
}


/**
* @brief Builds broken line.
*
* Uses provided segments list to build any possible 
* beroken line out of this list. Broken line can be
* cycled but cannot have branches (every node has
* only two neighbours).
*
* @param segmetns list of segments (pairs of integers).
*
* @return vector of broken lines.
*/
std::vector<std::vector<int> > buildBrokenLine(
	const std::vector<std::pair<int, int> > segments) { 
	int 
		a,
		b,
		i,
		j;
	std::vector<int> line;
	std::vector<std::vector<int> > brokenLine;
	
	// PROBLEMS HERE
	// 1. 12314 -> 1231 stop
	// 2. LOOK FOR AVAILABLE EXISTING LINES not to make 12, 134, 25 -> 125, 134
	for (i=0; i < segments.size(); ++i) {
		line.clear();
		for (j=i; j < segments.size(); ++j) {
			a = segments[j].first;
			b = segments[j].second;
			if (a != b && line.size() == 0) {
				std::cout << "empty and put both\n";
				line.push_back(a);
				line.push_back(b);
				std::cout << line[0] << line[1] << line[2] << std::endl;			
			} else if (a != b && std::find(line.begin(), line.end(), a) != line.end()) {
				std::cout << "not empty but has following found\n";
				line.push_back(b);
				std::cout << line[0] << line[1] << line[2] << std::endl;			
			} else if (std::find(line.begin(), line.end(), b) != line.end()) {
				std::cout << "cycle found\n";
				line.push_back(b);
				break;
			} else if (std::find(line.begin(), line.end(), a) != line.end() && a == line[0]) {
				std::cout << "cycle blocked\n";
				break;
			} else { break; }
		}
		std::cout << "Line being saved!\n";	
		brokenLine.push_back(line);	
	}

	return brokenLine;
}

