#include "segments.h"
#include <iostream>
#include <map>

int main(int argc, char** argv) {

	std::map<int, int> segments;
	int 
		numberOfSegments,
		i,
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
		segments[a] = b;
	}
	
	
	return 0;
}

