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
* broken line out of this list. Broken line can be
* cycled but cannot have branches (every node can occur
* only in a singe broken line). Also broken lines cannot 
* be formed by two vertices because in this case it will
* not differ from a segment.
*
* @param segments segments to create broken lines.
*
* @return void.
*/
std::vector<std::vector<int> > buildBrokenLine(const std::vector<std::pair<int, int> > segments); 
	
#endif // segments_h

