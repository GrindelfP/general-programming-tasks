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
	
	// ======================= //
	// SEGMENTS INITIALIZATION //
	// ======================= //
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
	
	// ===================== //
	// BUILDING BROKEN LINES //
	// ===================== //
	brokenLine = buildBrokenLine(segments);
		

	// ================== //
	// OUTPUT BROKEN LINE //
	// ================== //
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
* broken line out of this list. These lines set should
* obey following rules:
*
* 1. Broken line vertex can have no more than 2 neighbours.
* 2. A vertex can be included only in a single broken line.
* 3. A cycle can be formed if broken line has simillar initial
* and final vertices. 
*
* @param segmetns list of segments (pairs of integers).
*
* @return vector of broken lines.
*/
std::vector<std::vector<int> > buildBrokenLine(const std::vector<std::pair<int, int> > segments) { 

	int i;
	std::vector<int> line;
	std::vector<std::vector<int> > 
				brokenLines,
				brokenLinesFiltered;

	// ====================== //
	// BUILD BROKEN LINES SET //
	// ====================== //
	for(std::pair<int, int> segment : segments) {
		std::pair<int, int> included = vertexIncluded(segment, brokenLines);
		if (included.first == 1) {
		// CASE: first of the pair is the end vertex  //
			brokenLines[included.second].push_back(segment.second); 	
		} else if (included.first == 2) {
		// CASE: second of the pair is the end vertex //
			brokenLines[included.second].push_back(segment.first); 	
		} else if (included.first == 3) {
		// CASE: cycle, i.e. first of pair is the start vertex // 
		// and second is the end vertex 		       //		
			brokenLines[included.second].push_back(segment.first); 	
		} else if (included.first == 4) {
		// CASE: cycle, i.e. second of pair is the start vertex // 
		// and first is the end vertex 				//	
			brokenLines[included.second].push_back(segment.second); 	
		} else {
		// CASE: if no vertices are included in any broken line //
			std::vector<int> newLine = { segment.first, segment.second };
			brokenLines.push_back(newLine);
		}
	}
	
	// ======================================= //
	// FILTER LINES WITH LENGTHS <= 2 VERTICES //
	// ======================================= //
	for (i = 0; i < brokenLines.size(); ++i) {
		if (brokenLines[i].size() > 2) 
			brokenLinesFiltered.push_back(brokenLines[i]);
	}
		
	return brokenLinesFiltered;
}

/**
* @brief Finds ocurances of given segment vertices 
*	in the set of broken lines.
* 
* Checks each of the broken lines and tries to find the
* occurance of the given segment vertices in any of them.
* If any occurance found it returns specific code and
* the index of the broken line, which contain common vertex.
* If no occurances were found it returns code 0 and index -1.
* SPECIFIC CODES:
*	0 - no occurances were found 
*	1 - first vertex is the last in the broken line 
*	2 - second vertex is the last in the broken line
*	3 - first vertex is the broken line's start vertex
*		and the first vertex is the line's end vertex.	  
*	4 - second vertex is the broken line's start vertex
*		and the first vertex is the line's end vertex.
* Thus, the output is a pair <int, int>, e.g. (0, -1) or (3, 2).
*
* @param segment segment for which the occurance of its vertices should be found.
* @param brokenLines broken lines which may contain vertices.
* 
* @return pair: code and index of the line.
*/
std::pair<int, int> vertexIncluded(
	const std::pair<int, int> segment, 
	const std::vector<std::vector<int> > brokenLines
) {
	int 
		i,
		code;
	
	for (i = 0; i < brokenLines.size(); ++i) {
		std::vector<int> line = brokenLines[i];
		int last = line.size() - 1;
		if (line[0] == line[last]) break; // CASE OF CYCLE: this line cannot be updated
		if (line[last] == segment.first) code = 1;
		else if (line[last] == segment.second) code = 2;
		else if (line[0] == segment.first && line[last] == segment.second) code = 3;
		else if (line[0] == segment.second && line[last] == segment.first) code = 4;
		else code = 0;

		if (code != 0) break;
		else if (i == brokenLines.size() - 1) {
			i = -1;
			break;	
		}
	}

	return { code, i };
}

