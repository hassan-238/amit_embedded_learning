#pragma once
#ifndef DS_DYNAMIC_ARRAY_H_
#define DS_DYNAMIC_ARRAY_H_
#include "result.h"
typedef struct dynamic_array
{
    int* data;
    size_t length;
    size_t capacity;
}DynamicArray;


DataStructureResult DynamicArray_Create(size_t initialCapacity,DynamicArray* arr);
DataStructureResult DynamicArray_Add(DynamicArray* arr,int element);
DataStructureResult DynamicArray_AddRange(DynamicArray* arr,int* data, size_t length);
DataStructureResult DynamicArray_Delete(DynamicArray* arr,size_t index);
DataStructureResult DynamicArray_Clear(DynamicArray* arr);
DataStructureResult DynamicArray_Free(DynamicArray* arr);
DataStructureResult DynamicArray_EnsureCapacity(DynamicArray* arr, size_t newCapacity);


#endif