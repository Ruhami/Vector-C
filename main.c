#include <stdio.h>
#include "vector.h"
#include "test.h"

int main()
{
	vector *myVector;
	void**output;
	size_t out;
	myVector = vectorGenerate(10);
	
	VALIDATE(vectorPush(myVector, (void*)1));
	VALIDATE(vectorPush(myVector, (void*)2));
	VALIDATE(vectorPush(myVector, (void*)3));
	VALIDATE(vectorPush(myVector, (void*)4));
	VALIDATE(vectorPush(myVector, (void*)5));
	VALIDATE(vectorInsert(myVector, 2 ,(void*)7));
	VALIDATE(vectorPop(myVector, output));
	VALIDATE(vectorRemove(myVector, 0, output));

	VALIDATE(vectorGetElement(myVector, 2, output));
	VALIDATE(vectorSetElement(myVector, 0, (void*)30));
	printf("GetSize: %lu\n",vectorGetSize(myVector));
	printf("GetCapacity: %lu\n",vectorGetCapacity(myVector));
    printf("Count: %lu\n",vectorCount(myVector,1));
	vectorDestroy(&myVector);
	
	return 0;
}
