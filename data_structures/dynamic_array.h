typedef struct dynamic_array
{
    int* data;
    size_t length;
    size_t capacity;
}DynamicArray;


DynamicArray DynamicArray_Create(size_t initialCapacity);
void DynamicArray_Add(DynamicArray* arr,int element);
void DynamicArray_AddRange(DynamicArray* arr,int* data, size_t length);
void DynamicArray_Delete(DynamicArray* arr,size_t index);
void DynamicArray_Clear(DynamicArray* arr);
void DynamicArray_Free(DynamicArray* arr);
void DynamicArray_EnsureCapacity(DynamicArray* arr, size_t newCapacity);