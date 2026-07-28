#include <stdlib.h>
#include "queue.h"

Queue Queue_Create(size_t initialSize)
{
    return DynamicArray_Create(initialSize);
}

void Queue_EnQueue(Queue* Queue,int element)
{
    DynamicArray_Add((DynamicArray*)Queue,element);
}
int Queue_DeQueue(Queue* Queue)
{
    if(Queue->length == 0)
        return -1;
    int element = Queue->data[0];
    DynamicArray_Delete((DynamicArray*)Queue,0);
    return element;
}