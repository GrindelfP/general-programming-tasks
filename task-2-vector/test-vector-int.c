#include "vector-int.h"
#include "tests.h"

#define INIT_SIZE 10

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
}

void Vectorint_testRemend() {

}

void VectorInt_testInsert() {

}

void VectorInt_testPop() {
	
}

