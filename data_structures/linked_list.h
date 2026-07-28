#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct doubly_node{
    int data;
    struct doubly_node* next;
    struct doubly_node* prev;
}DoublyNode;



//Operations
//1- Add Begining
//2- Add At
//3- Add Ending

//4- Delete Begining
//5- Delete At
//6- Delete Ending
Node* Node_Create(const int data);

DoublyNode* DoublyNode_Create(const int data);
//All functions return the Head Node of the linked list

//Linked List ==============================
Node* LinkedList_Create(const int* data, const size_t size);

Node* LinkedList_AddBegin(const Node* head, const int data);
Node* LinkedList_AddAt(const Node* head, const int data, int index);
Node* LinkedList_AddEnd(const Node* head, const int data);

Node* LinkedList_DeleteBegin(const Node* head);
Node* LinkedList_DeleteAt(const Node* head, int index);
Node* LinkedList_DeleteEnd(const Node* head);

void LinkedList_Free(const Node* head);
//Doubly Linked List ==============================
DoublyNode* DoublyLinkedList_Create(const int* data, const size_t size);

DoublyNode* DoublyLinkedList_AddBegin(const DoublyNode* head, const int data);
DoublyNode* DoublyLinkedList_AddAt(const DoublyNode* head, const int data, int index);
DoublyNode* DoublyLinkedList_AddEnd(const DoublyNode* head, const int data);

DoublyNode* DoublyLinkedList_DeleteBegin(const DoublyNode* head);
DoublyNode* DoublyLinkedList_DeleteAt(const DoublyNode* head, int index);
DoublyNode* DoublyLinkedList_DeleteEnd(const DoublyNode* head);

void DoublyLinkedList_Free(const DoublyNode* head);
//Circular Linked List ==============================
Node* CircularLinkedList_Create(const int* data, const size_t size);

Node* CircularLinkedList_AddBegin(const Node* head, const int data);
Node* CircularLinkedList_AddAt(const Node* head, const int data, int index);
Node* CircularLinkedList_AddEnd(const Node* head, const int data);

Node* CircularLinkedList_DeleteBegin(const Node* head);
Node* CircularLinkedList_DeleteAt(const Node* head, int index);
Node* CircularLinkedList_DeleteEnd(const Node* head);

void CircularLinkedList_Free(const Node* head);

//Doubly Circular Linked List ==============================
DoublyNode* DoublyCircularLinkedList_Create(const int* data, const size_t size);

DoublyNode* DoublyCircularLinkedList_AddBegin(const DoublyNode* head, const int data);
DoublyNode* DoublyCircularLinkedList_AddAt(const DoublyNode* head, const int data, int index);
DoublyNode* DoublyCircularLinkedList_AddEnd(const DoublyNode* head, const int data);

DoublyNode* DoublyCircularLinkedList_DeleteBegin(const DoublyNode* head);
DoublyNode* DoublyCircularLinkedList_DeleteAt(const DoublyNode* head, int index);
DoublyNode* DoublyCircularLinkedList_DeleteEnd(const DoublyNode* head);

void DoublyCircularLinkedList_Free(const DoublyNode* head);

#endif