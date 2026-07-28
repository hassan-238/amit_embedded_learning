#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "dynamic_array.h"
#include "stack.h"
#include "queue.h"


void LinkedList_Print(const Node *node)
{
    for (; node != NULL; node = node->next)
    {
        printf("[%d] -> ", node->data);
    }

    printf("NULL\n");
}
void DoublyLinkedList_Print(const DoublyNode *node)
{
    for (; node != NULL; node = node->next)
    {
        printf("[%d] -> ", node->data);
    }

    printf("NULL\n");
}
void CircularLinkedList_Print(const Node *node)
{
    
    printf("%p  ",node);
    printf("[%d] -> ", node->data);
    
    Node* head = node;
    node = node->next;
    for (; node != head; node = node->next)
    {
        printf("[%d] -> ", node->data);
    }

    printf("NULL\n");
}

void DoublyCircularLinkedList_Print(const DoublyNode *node)
{
    printf("%p  ",node);
    printf("[%d] -> ", node->data);
    
    DoublyNode* head = node;
    node = node->next;
    for (; node != head; node = node->next)
    {
        printf("[%d] -> ", node->data);
       
    }
    
    printf("NULL\n");
}
void LinkedList_Test(const int *data, size_t size)
{
    Node *node = LinkedList_Create(data, size);
    LinkedList_Print(node);

    node = LinkedList_AddBegin(node, 12);
    LinkedList_Print(node);

    node = LinkedList_AddAt(node, 334, 2);
    LinkedList_Print(node);

    node = LinkedList_AddEnd(node, 32);
    LinkedList_Print(node);

    node = LinkedList_DeleteBegin(node);
    LinkedList_Print(node);

    node = LinkedList_DeleteAt(node, 1);
    LinkedList_Print(node);

    node = LinkedList_DeleteEnd(node);
    LinkedList_Print(node);

    node = LinkedList_DeleteAt(node, 4);
    LinkedList_Print(node);

    LinkedList_Free(node);
}

void DoublyLinkedList_Test(const int *data, size_t size)
{
    DoublyNode *node = DoublyLinkedList_Create(data, size);
    DoublyLinkedList_Print(node);

    node = DoublyLinkedList_AddBegin(node, 12);
    DoublyLinkedList_Print(node);

    node = DoublyLinkedList_AddAt(node, 334, 2);
    DoublyLinkedList_Print(node);

    node = DoublyLinkedList_AddEnd(node, 32);
    DoublyLinkedList_Print(node);

    node = DoublyLinkedList_DeleteBegin(node);
    DoublyLinkedList_Print(node);

    node = DoublyLinkedList_DeleteAt(node, 1);
    DoublyLinkedList_Print(node);

    node = DoublyLinkedList_DeleteEnd(node);
    DoublyLinkedList_Print(node);

    node = DoublyLinkedList_DeleteAt(node, 4);
    DoublyLinkedList_Print(node);

    DoublyLinkedList_Free(node);
}
void CircularLinkedList_Test(const int *data, size_t size)
{
    Node *node = CircularLinkedList_Create(data, size);
    CircularLinkedList_Print(node);

    node = CircularLinkedList_AddBegin(node, 12);
    CircularLinkedList_Print(node);

    node = CircularLinkedList_AddAt(node, 334, 2);
    CircularLinkedList_Print(node);

    node = CircularLinkedList_AddEnd(node, 32);
    CircularLinkedList_Print(node);

    node = CircularLinkedList_DeleteBegin(node);
    CircularLinkedList_Print(node);

    node = CircularLinkedList_DeleteAt(node, 1);
    CircularLinkedList_Print(node);

    node = CircularLinkedList_DeleteEnd(node);
    CircularLinkedList_Print(node);

    node = CircularLinkedList_DeleteAt(node, 4);
    CircularLinkedList_Print(node);

    CircularLinkedList_Free(node);
}
void DoublyCircularLinkedList_Test(const int *data, size_t size)
{
    DoublyNode *node = DoublyCircularLinkedList_Create(data, size);
    DoublyCircularLinkedList_Print(node);

    node = DoublyCircularLinkedList_AddBegin(node, 12);
    DoublyCircularLinkedList_Print(node);

    node = DoublyCircularLinkedList_AddAt(node, 334, 2);
    DoublyCircularLinkedList_Print(node);

    node = DoublyCircularLinkedList_AddEnd(node, 32);
    DoublyCircularLinkedList_Print(node);

    node = DoublyCircularLinkedList_DeleteBegin(node);
    DoublyCircularLinkedList_Print(node);

    node = DoublyCircularLinkedList_DeleteAt(node, 1);
    DoublyCircularLinkedList_Print(node);

    node = DoublyCircularLinkedList_DeleteEnd(node);
    DoublyCircularLinkedList_Print(node);

    node = DoublyCircularLinkedList_DeleteAt(node, 4);
    DoublyCircularLinkedList_Print(node);

    DoublyCircularLinkedList_Free(node);
}
void DynamicArray_Print(const DynamicArray* arr)
{
    for(int i = 0; i < arr->length; i++)
    {
        printf("%d ,",arr->data[i]);
    }
    printf("[%d, %d]\n",arr->length, arr->capacity);
}
void DynamicArray_Test(int* data,size_t size)
{
    DynamicArray arr = DynamicArray_Create(size);
    DynamicArray_Print(&arr);

    DynamicArray_Add(&arr,11);
    DynamicArray_Print(&arr);

    DynamicArray_AddRange(&arr,data,size);
    DynamicArray_Print(&arr);

    DynamicArray_EnsureCapacity(&arr,31);
    DynamicArray_Print(&arr);

    DynamicArray_Delete(&arr,3);
    DynamicArray_Print(&arr);

    DynamicArray_Clear(&arr);
    DynamicArray_Print(&arr);

    DynamicArray_Free(&arr);
}
void Stack_Test(int* data, size_t size)
{
    Stack stack = Stack_Create(size);
    for(int i = 0 ; i < size;i ++)
        Stack_Push(&stack,data[i]);
    DynamicArray_Print(&stack);
    int result = Stack_Pop(&stack);
    DynamicArray_Print(&stack);
    printf("Popped: %d\n",result);
    DynamicArray_Free((DynamicArray*)&stack);
}
void Queue_Test(int* data, size_t size)
{
    Queue stack = Queue_Create(size);
    for(int i = 0 ; i < size;i ++)
        Queue_EnQueue(&stack,data[i]);
    DynamicArray_Print(&stack);
    int result = Queue_DeQueue(&stack);
    DynamicArray_Print(&stack);
    printf("DeQueues: %d\n",result);
    DynamicArray_Free((DynamicArray*)&stack);
}
int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("============================\n");
    LinkedList_Test(numbers, size);
    printf("============================\n");
    DoublyLinkedList_Test(numbers, size);
    printf("============================\n");
    CircularLinkedList_Test(numbers, size);
    printf("============================\n");
    DoublyCircularLinkedList_Test(numbers, size);
    printf("============================\n");
    DynamicArray_Test(numbers,size);
    printf("============================\n");
    Stack_Test(numbers,size);
    printf("============================\n");
    Queue_Test(numbers,size);
    printf("============================\n");

    return 0;
}