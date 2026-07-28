#include <stdlib.h>
#include "stack.h"

Stack Stack_Create(size_t initialSize)
{
    return DynamicArray_Create(initialSize);
}

void Stack_Push(Stack* stack,int element)
{
    DynamicArray_Add((DynamicArray*)stack,element);
}
int Stack_Pop(Stack* stack)
{
    
    if(stack->length == 0)
        return -1;
    int element = stack->data[stack->length-1];
    DynamicArray_Delete((DynamicArray*)stack,stack->length-1);
    return element;
}