#include <stdio.h>
#include "vector.h"
#define bool int 

struct vector {
    void** items;
    size_t capacity;
    size_t total;
};

size_t getCapPowTow(size_t cap)
{
	size_t num = 1;
	if (cap == 0)
		return 0;

	while (num < cap)
		num *= 2;

	return num;
}

vector* vectorGenerate(size_t cap)
{
	vector* v = malloc(sizeof(vector));
	if (v == NULL)
		return NULL;

	cap = getCapPowTow(cap);
	
	if (cap == 0)
		return NULL;

	v->items = malloc(sizeof(void *) *cap);
	if (v->items == NULL)
	{
		free(v);
		return NULL;
	}

	v->capacity = cap;
    v->total = 0;

	return v;
}

void vectorDestroy(vector **v)
{
	if ( v == NULL || *v == NULL)
		return;

	free((*v)->items);
	free(*v);
	*v = NULL;
}
 

static ErrorCode vectorResize(vector *v, size_t capacity)
{
    void**items = realloc(v->items, sizeof(void*) * v->capacity * 2);
    if (items == NULL)
		return E_ALLOCATION_ERROR;
 
	v->items = items;
    v->capacity *= 2;
	return E_OK;
}

ErrorCode vectorPush(vector *v, void* item)
{
	if (v == NULL)
		return E_NULL_PTR;

    if (v->capacity == v->total)
	{
		ErrorCode err = vectorResize(v, v->capacity);
		if (err != E_OK)
		{
			return err;
		}
	}
    v->items[v->total++] = item;
	return E_OK;
}

static void moveElementsForward(vector *v, size_t index)
{
	size_t i;
	for (i = v->total; i > index; --i)
	{
		v->items[i] = v->items[i - 1];
	}
}

ErrorCode vectorInsert(vector *v, size_t index, void* item)
{
	if (v == NULL)
		return E_NULL_PTR;

    if (index > v->total)
		return E_BAD_INDEX;

	if (index == v->total)
		return vectorPush(v, item);

	if (v->capacity == v->total)
	{
    	ErrorCode err = vectorResize(v, v->capacity);
		if (err != E_OK)
			return err;
	}
	
	moveElementsForward(v, index);

    v->items[index] = item;
	++(v->total);
    return E_OK;
}

ErrorCode vectorPop(vector *v, void**val)
{	
	if (v == NULL)
		return E_NULL_PTR;

    if (v->total == 0)
		return E_UNDERFLOW;

	val = v->items[--v->total];
	return E_OK;
}

static void moveElementsBackward(vector *v, size_t index)
{
	size_t i;
	for (i = index; i < v->total - 1; ++i)
        v->items[i] = v->items[i + 1];
}

ErrorCode vectorRemove(vector *v, int index, void* *val)
{
	if (v == NULL)
		return E_NULL_PTR;

    if (index >= v->total)
        return E_BAD_INDEX;

	val = v->items[index];
    moveElementsBackward(v, index);
    
    --(v->total);
    return E_OK;
}

ErrorCode vectorGetElement(vector *v, size_t index, void* *val)
{
	if (v == NULL)
		return E_NULL_PTR;

    if (index >= v->total)
        return E_BAD_INDEX;

    val =  v->items[index];
    return E_OK;
}

ErrorCode vectorSetElement(vector *v, size_t index, void* item)
{
	if (v == NULL)
		return E_NULL_PTR;

    if (index >= v->total)
        return E_BAD_INDEX;

    v->items[index] = item;
	return E_OK;
}

size_t vectorGetSize(vector *v)
{
	return (v == NULL) ? 0 : v->total;
}

size_t vectorGetCapacity(vector *v)
{
	return (v == NULL) ? 0 : v->capacity;;
}

size_t vectorCount(vector *v, void* value)
{
    size_t i;
	size_t counter = 0;
	if (v == NULL)
		return 0;

	for (i = 0; i < v->total; ++i)
	{
		if (v->items[i] == value)
		{
			++counter;
		}
	}
	return counter;
}





#ifdef _DEBAG
void vectorPrint(vector *v)
{	
	size_t i;
	for (i = 0; i < v->total; ++i)
	{
		printf("%d\n", v->items[i]);
	}
}
#endif


/*void foreach(int arr[], size_t size, int(*action)(int* carrent))
{
	size_t i = 0;
	while(!action(&arr[i++]) && size--);
	return i - 1;
}

int action(int* carrent)
{
	const int x = 7;
	return x == *carrent;
}*/







