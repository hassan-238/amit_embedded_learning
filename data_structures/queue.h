#include "dynamic_array.h"

typedef DynamicArray Queue;

Queue Queue_Create(size_t initialSize);

void Queue_EnQueue(Queue* Queue,int element);
int Queue_DeQueue(Queue* Queue);