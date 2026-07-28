#include "dynamic_array.h"

typedef DynamicArray Stack;


Stack Stack_Create(size_t initialSize);

void Stack_Push(Stack* stack,int element);
int Stack_Pop(Stack* stack);