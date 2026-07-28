#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


//Operations
//1- Add Begining
//2- Add At
//3- Add Ending

//4- Delete Begining
//5- Delete At
//6- Delete Ending

//All functions return the Head Node of the linked list


Node* Node_Create(const int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

DoublyNode* DoublyNode_Create(const int data)
{
    DoublyNode* node = (DoublyNode*)malloc(sizeof(DoublyNode));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
}

//Linked List ==============================
Node* LinkedList_Create(const int* data, const size_t size)
{
    if(size == 0)
        return NULL;
    Node* head = Node_Create(data[0]);
    Node* currentNode = head;
    for(int i = 1; i < size; i++)
    {
        Node* nextNode = Node_Create(data[i]);
        
        currentNode->next = nextNode;
        currentNode = currentNode->next;    
        
    }
    return head;
}

Node* LinkedList_AddBegin(const Node* head, const int data)
{
    Node* node = Node_Create(data);
    node->next = head;
    return node;
}
Node* LinkedList_AddAt(const Node* head, const int data, int index)
{
    Node* node = Node_Create(data);
    Node* currentNode = head;
    if(index == 0)
        return LinkedList_AddBegin(head,data);
    while(index-- > 1)
    {
        currentNode = currentNode->next;
        if(currentNode == NULL)
        {
            return NULL;
        }
    }
    Node* after = currentNode->next;
    Node* before = currentNode;
    before->next = node;
    node->next = after;
    // node->next = currentNode->next;
    // currentNode->next = node;
    return head;
}
Node* LinkedList_AddEnd(const Node* head, const int data)
{
    Node* node = Node_Create(data);
    Node* currentNode = head;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = node;
    return head;
}

Node* LinkedList_DeleteBegin(const Node* head)
{
    Node* newHead = head->next;
    free(head);
    return newHead;
}
Node* LinkedList_DeleteAt(const Node* head, int index)
{
    Node* currentNode = head;
    if(index == 0)
        return LinkedList_DeleteBegin(head);
    while(index-- > 1)
    {
        currentNode = currentNode->next;
        if(currentNode == NULL || currentNode->next == NULL)
        {
            return NULL;
        }
    }
    Node* nodeToDelete = currentNode->next;
    currentNode->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}
Node* LinkedList_DeleteEnd(const Node* head)
{
    Node* currentNode = head;
    while(currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }
    free(currentNode->next);
    currentNode->next = NULL;

    return head;
}

void LinkedList_Free(const Node* head)
{
    Node* currentNode = head;
    while(currentNode != NULL)
    {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}
//Doubly Linked List ==============================
DoublyNode* DoublyLinkedList_Create(const int* data, const size_t size)
{
    if(size == 0)
        return NULL;
    DoublyNode* head = DoublyNode_Create(data[0]);
    DoublyNode* currentNode = head;
    for(int i = 1; i < size; i++)
    {
        DoublyNode* nextNode = DoublyNode_Create(data[i]);
        currentNode->next = nextNode;
        nextNode->prev = currentNode;
        currentNode = nextNode;    
    }
    return head;
}

DoublyNode* DoublyLinkedList_AddBegin(const DoublyNode* head, const int data)
{
    DoublyNode* node = DoublyNode_Create(data);
    node->next = head;
    DoublyNode* headNode = head;
    headNode->prev = node;

    return node;
}
DoublyNode* DoublyLinkedList_AddAt(const DoublyNode* head, const int data, int index)
{
    DoublyNode* node = DoublyNode_Create(data);
    DoublyNode* currentNode = head;
    if(index == 0)
        return DoublyLinkedList_AddBegin(head,data);
    while(index-- > 0)
    {
        currentNode = currentNode->next;
        if(currentNode == NULL)
        {
            return NULL;
        }
    }
    currentNode->prev->next = node;
    node->prev = currentNode->prev;
    node->next = currentNode;
    currentNode->prev = node;
    
    return head;
}
DoublyNode* DoublyLinkedList_AddEnd(const DoublyNode* head, const int data)
{
    DoublyNode* node = DoublyNode_Create(data);
    DoublyNode* currentNode = head;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = node;
    node->prev = currentNode;
    return head;
}

DoublyNode* DoublyLinkedList_DeleteBegin(const DoublyNode* head)
{
    DoublyNode* newHead = head->next;
    newHead->prev = NULL;
    free(head);
    return newHead;
}
DoublyNode* DoublyLinkedList_DeleteAt(const DoublyNode* head, int index)
{
    DoublyNode* currentNode = head;
    if(index == 0)
        return DoublyLinkedList_DeleteBegin(head);
    
    while(index-- > 0)
    {
        currentNode = currentNode->next;
        if(currentNode == NULL)
        {
            return NULL;
        }
    }
    
    DoublyNode* before = currentNode->prev;
    DoublyNode* after = currentNode->next;
    before->next = after;
    if(after != NULL)
    {
        after->prev = before;
    }
    free(currentNode);
    return head;
}
DoublyNode* DoublyLinkedList_DeleteEnd(const DoublyNode* head)
{
    DoublyNode* currentNode = head;
    while(currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }
    free(currentNode->next);
    currentNode->next = NULL;

    return head;
}

void DoublyLinkedList_Free(const DoublyNode* head)
{
    DoublyNode* currentNode = head;
    while(currentNode != NULL && currentNode->next != NULL)
    {
        currentNode = currentNode->next;
        free(currentNode->prev);
    }
}
//Circular Linked List ==============================

Node* CircularLinkedList_Create(const int* data, const size_t size)
{
    if(size == 0)
        return NULL;
    Node* head = Node_Create(data[0]);
    Node* currentNode = head;
    for(int i = 1; i < size; i++)
    {
        Node* nextNode = Node_Create(data[i]);
        currentNode->next = nextNode;
        currentNode = nextNode;    
    }
    //at end of loop the current node will be the end node
    currentNode->next = head;

    return head;
}

Node* CircularLinkedList_GetEnd(const Node* head)
{
    Node* node = head;
    while(node->next != head)
    {
        node = node->next;
    }
    return node;
}
Node* CircularLinkedList_AddBegin(const Node* head, const int data)
{
    Node* endNode = head;
    while(endNode->next != head)
    {
            endNode = endNode->next;
    }
    Node* node = Node_Create(data);

    node->next = head;
    endNode->next = node;
    return node;
}

Node* CircularLinkedList_AddAt(const Node* head, const int data, int index)
{
    Node* node = Node_Create(data);
    Node* currentNode = head;
    if(index == 0)
        return CircularLinkedList_AddBegin(head,data);
    while(index-- > 1)
    {
        currentNode = currentNode->next;
        if(currentNode == head || currentNode->next == head)
        {
            return NULL;
        }
    }
    Node* before = currentNode;
    Node* after = currentNode->next;
    before->next = node;
    node->next = after;
    
    
    return head;
}
Node* CircularLinkedList_AddEnd(const Node* head, const int data)
{
    Node* end = CircularLinkedList_GetEnd(head);
    Node* node = Node_Create(data);

    end->next = node;
    node->next = head;

    return head;
}

Node* CircularLinkedList_DeleteBegin(const Node* head)
{
    Node* end = CircularLinkedList_GetEnd(head);
    end->next = head->next;
    free(head);
    return end->next;
}
Node* CircularLinkedList_DeleteAt(const Node* head, int index)
{
    if(index == 0)
        return CircularLinkedList_DeleteBegin(head);
    Node* currentNode = head;
    while(index-- > 1)
    {
        currentNode = currentNode->next;
        if(currentNode == head || currentNode->next == head)
        {
            return NULL;
        }
    }
   
    Node* nodeToDelete = currentNode->next;
    currentNode->next = currentNode->next->next;
    
    free(nodeToDelete);
    
    return head;
}
Node* CircularLinkedList_DeleteEnd(const Node* head)
{
    Node* currentNode = head;
    while(currentNode->next->next != head)
    {
        currentNode = currentNode->next;
    }
    Node* end = currentNode->next;
    currentNode->next = head;
    free(end);

    return head;
}

void CircularLinkedList_Free(const Node* head)
{
    Node* currentNode = head;
    while(currentNode != head)
    {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}

//Doubly Circular Linked List ==============================
DoublyNode* DoublyCircularLinkedList_Create(const int* data, const size_t size)
{
    if(size == 0)
        return NULL;
    DoublyNode* head = DoublyNode_Create(data[0]);
    DoublyNode* currentNode = head;
    for(int i = 1; i < size; i++)
    {
        DoublyNode* nextNode = DoublyNode_Create(data[i]);
        currentNode->next = nextNode;
        nextNode->prev = currentNode;
        currentNode = nextNode;    
    }
    //connect the head and end nodes 
    currentNode->next = head;
    head->prev = currentNode;
    return head;
}

DoublyNode* DoublyCircularLinkedList_AddBegin(const DoublyNode* head, const int data)
{
    DoublyNode* node = DoublyNode_Create(data);
    DoublyNode* end = head->prev;
    DoublyNode* headNode = head;
    end->next = node;
    headNode->prev = node;
    node->next = head;
    node->prev = end;
    return node;
}
DoublyNode* DoublyCircularLinkedList_AddAt(const DoublyNode* head, const int data, int index)
{
    DoublyNode* node = DoublyNode_Create(data);
    DoublyNode* currentNode = head;
    if(index == 0)
        return DoublyCircularLinkedList_AddBegin(head,data);
    while(index-- > 0)
    {
        currentNode = currentNode->next;
        if(currentNode == head)
        {
            return NULL;
        }
    }
    currentNode->prev->next = node;
    node->prev = currentNode->prev;
    node->next = currentNode;
    currentNode->prev = node;   

    return head;
}
DoublyNode* DoublyCircularLinkedList_AddEnd(const DoublyNode* head, const int data)
{
    DoublyNode* end = head->prev;
    DoublyNode* node = DoublyNode_Create(data);

    end->next = node;
    node->prev = end;
    
    DoublyNode* headNode = head;
    headNode->prev = node;
    node-> next = head;

    return head;
}

DoublyNode* DoublyCircularLinkedList_DeleteBegin(const DoublyNode* head)
{
    DoublyNode* newHead = head->next;
    DoublyNode* end = head->prev;

    end->next = newHead;
    newHead->prev = end;

    free(head);

    return newHead;

}
DoublyNode* DoublyCircularLinkedList_DeleteAt(const DoublyNode* head, int index)
{
    DoublyNode* currentNode = head;
    if(index == 0)
        return DoublyCircularLinkedList_DeleteBegin(head);
    while(index-- > 1)
    {
        currentNode = currentNode->next;
        if(currentNode == head || currentNode->next == head)
        {
            return NULL;
        }
    }
    DoublyNode* nodeToDelete = currentNode->next;
    DoublyNode* before = currentNode;
    DoublyNode* after = currentNode->next->next;
    before->next = after;
    after->prev = before;
    free(nodeToDelete);
    return head;
}
DoublyNode* DoublyCircularLinkedList_DeleteEnd(const DoublyNode* head)
{
    DoublyNode* end = head->prev;
    DoublyNode* headNode = head;

    headNode->prev = end->prev;
    end->prev->next = headNode;

    free(end);

    return head;
}

void DoublyCircularLinkedList_Free(const DoublyNode* head)
{
    DoublyNode* currentNode = head;
    while(currentNode != head && currentNode->next != head)
    {
        currentNode = currentNode->next;
        free(currentNode->prev);
    }
}
