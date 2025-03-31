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
	
	// ====================
	// BUILDING BROKEN LINE
	// ====================
	buildBrokenLine(segments, brokenLine);
		

	// ==================
	// OUTPUT BROKEN LINE
	// ==================
	if (brokenLione.size()  == 0) std::cout << "There is no broken lines built!\n";
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
* @param brokenLine list of broken lines.
*
* @return void.
*/
void buildBrokenLine(
	const std::vector<std::pair<int, int> > segments, 
	std::vector<std::vector<int> > brokenLine
) { 
	
	for (std::pair<int, int> segment : segments) {
		
	}			

	return;
}

