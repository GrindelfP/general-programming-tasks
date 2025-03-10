#include "vector-int.h"

int main(int argc, char** argv) {

	int size = 10;

	IVectorInt vectorint = initVectorInt(size);

	for (int i = 0; i < size * 2; ++i) {
		appendToVectorInt(vectorint, i);
	}

	int* data = getDataFromVectorInt(vectorint);

	for (int i = 0; i < size; ++i) {
		printf("%d", data[i]);
	}

	return 0;
}

