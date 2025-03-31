/*
*
*	Task 4: Segments. 
*	Created by GrindelfP on 2024-03-30.
*	
* 	TODO 2025-03-31: not all broken lines are 'captured'
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
	std::cout << "\n====================\nBROKEN LINES BUILDER\n====================\n";
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
	std::cout << "==================================\n";
	if (brokenLine.size()  == 0) std::cout << "There is no broken lines built!\n";
	else {
		for (i = 0; i < brokenLine.size(); ++i) {
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
* broken line out of this list. Broken line can be
* cycled but cannot have branches (every node can occur
* only in a singe broken line). Also broken lines cannot 
* be formed by two vertices because in this case it will
* not differ from a segment.
*
* @param segmetns list of segments (pairs of integers).
*
* @return vector of broken lines.
*/
std::vector<std::vector<int> > buildBrokenLine(const std::vector<std::pair<int, int> > segments) { 

	int 
		a,
		b,
		i,
		j,
		last;
	std::vector<int> line;
	std::vector<std::vector<int> > brokenLine;
	
	for (i=0; i < segments.size(); ++i) {
		if (a == b) break;
		line.clear();
		line.push_back(segments[i].first);
		line.push_back(segments[i].second);
		for (j=i; j < segments.size(); ++j) {
			a = segments[j].first;
			b = segments[j].second;
			last = line.size()-1;
			if (line[last] == a && line[0] != b) {
				// STANDARD CASE (....2 + 2 3 -> ....2 3)
				line.push_back(b);
				j=i;
			} else if (line[last] == a && line[0] == b) {
				// CYCLE CASE (1 .... 3 + 3 1 -> 1 .... 3 1)
				// cycles can only be formed with initial node
				line.push_back(b);
				break;
			} 
		}
		if (line.size() > 2) brokenLine.push_back(line);	
	}
	
	return brokenLine;
}

