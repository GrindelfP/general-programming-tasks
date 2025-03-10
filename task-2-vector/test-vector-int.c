#include "vector-int.h"
#include "tests.h"
#include <stdio.h>

#define INIT_SIZE 10

// TODO: ADD NEGATIVE TESTS
// TODO: ADD AND ARRANGE INCLUDE SCOPES

int main(int argc, char** argv) {

	VectorInt_testAppend();
	Vectorint_testRemend();
	VectorInt_testInsert();
	VectorInt_testPop();

	return 0;
}


void VectorInt_testAppend() {

	IVectorInt vector = initVectorInt(0);
	
	appendToVectorInt(vector, 10);

	int* dataFromVector = getDataFromVectorInt(vector);
	printf("%d\n", *dataFromVector);

	disposeVectorInt(vector);
}

void Vectorint_testRemend() {

}

void VectorInt_testInsert() {

}

void VectorInt_testPop() {
	
}

