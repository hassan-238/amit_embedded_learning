#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

DynamicArray DynamicArray_Create(size_t initialCapacity)
{
    DynamicArray arr;
   
    size_t capacity = 2;
    while(initialCapacity > capacity)
    {
        capacity *= 2;
    }
    arr.capacity = capacity;
    arr.data = malloc(sizeof(arr.data[0]) * arr.capacity);
    arr.length = 0;
    return arr;
}
void DynamicArray_Add(DynamicArray* arr,int element)
{
    DynamicArray_EnsureCapacity(arr,arr->length + 1);
    arr->data[arr->length] = element;
    arr->length++;
}
void DynamicArray_AddRange(DynamicArray* arr, int* data, size_t length)
{
    DynamicArray_EnsureCapacity(arr,arr->length + length);
   
    for(int i = 0;i < length; i++)
    {
        arr->data[i + arr->length] = data[i];
    }
    arr->length += length;
}
void DynamicArray_Delete(DynamicArray* arr,size_t index)
{
    if(index >= arr->length)
        return;
    for(int i = index;i < arr->length-1; i++)
    {
        arr->data[i] = arr->data[i+1];
    }
    arr->length--;
}
void DynamicArray_Clear(DynamicArray* arr)
{
    memset(arr->data,0,arr->capacity * sizeof(arr->data[0]));
    arr->length = 0;
}
void DynamicArray_Free(DynamicArray* arr)
{
    free(arr->data);
    arr->data = NULL;
}

void DynamicArray_EnsureCapacity(DynamicArray* arr, size_t newCapacity){
    if(newCapacity > arr->capacity)
    {
        if(arr->capacity <= 0)
            arr->capacity = 2;
        while(newCapacity > arr->capacity)
        {
            arr->capacity *= 2;
        }

        arr->data = realloc(arr->data, arr->capacity*sizeof(arr->data[0]));
    }
}