/**
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
* beroken line out of this list. Broken line can be
* cycled but cannot have branches (every node has
* only two neighbours).
*
* @param segmetns list of segments (pairs of integers).
*
* @return void.
*/
std::vector<std::vector<int> > buildBrokenLine(
	const std::vector<std::pair<int, int> > segments); 
	

#endif // segments_h

