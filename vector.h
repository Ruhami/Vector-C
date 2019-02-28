#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct vector vector;
typedef enum
{
	E_OK,
	E_NULL_PTR,
	E_UNDERFLOW,
	E_ALLOCATION_ERROR,
	E_BAD_INDEX
} ErrorCode;
	
vector* vectorGenerate(size_t cap);
void vectorDestroy(vector **v);

ErrorCode vectorPush(vector *v, void *item);
ErrorCode vectorInsert(vector *v, size_t index, void* item);

ErrorCode vectorPop(vector *v, void**val);
ErrorCode vectorRemove(vector *v, int index, void**val); 

ErrorCode vectorGetElement(vector *v, size_t index, void**val);
ErrorCode vectorSetElement(vector *v, size_t index, void* item);

size_t vectorGetSize(vector *v);
size_t vectorGetCapacity(vector *v); 
size_t vectorCount(vector *v, void* value);

/*#ifdef _DEBAG*/
void vectorPrint(vector *v);
/*#endif*/

#endif
