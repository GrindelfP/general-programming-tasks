/*
*
*	Task 4: Segments. 
*	Created by GrindelfP on 2024-03-30.
*
*/

#ifndef segments_h
#define segments_h

#include <vector>
#include <utility>


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
std::vector<std::vector<int> > buildBrokenLine(const std::vector<std::pair<int, int> > segments); 


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
);
	
#endif // segments_h

