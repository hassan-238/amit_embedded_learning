#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
} NODE;


NODE* NODE_Create(int data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
}
void NODE_PrintList(NODE* head)
{
  for(NODE* node = head;node != NULL; node = node->next)
    {
        printf("%d -> ",node->data);
    }   
}

NODE* NODE_InsetBegining(NODE* head,int data)
{
    NODE* node = NODE_Create(data);
    node->next = head;

    return node;

}

NODE* NODE_InsetEnding(NODE* head,int data)
{

    NODE* node = NODE_Create(data);
    while(head->next!=NULL)
        head = head->next;

    head->next = node;
    return node;

}


NODE* NODE_InsertAt(NODE* head,int index, int data)
{
    NODE* node = NODE_Create(data);
    if(index == 0)
    {
        NODE_InsetBegining(head,data);
    }
    while(index > 1 && head->next != NULL)
    {
        index--;
        head = head->next;
    }
    NODE* after = head->next;
    NODE* prev = head;
    prev->next = node;
    node->next = after;
    return node;
}

int main(void)
{
    NODE* n1 = (NODE*)malloc(sizeof(NODE));
    NODE* n2 = (NODE*)malloc(sizeof(NODE));
    NODE* n3 = (NODE*)malloc(sizeof(NODE));

    n1->data = 1;
    n2->data = 2;
    n3->data = 3;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    n1 = NODE_InsetBegining(n1,12);
    NODE_InsetEnding(n1,13);
    NODE_InsertAt(n1,300,255);
    NODE_InsertAt(n1,2,255);
    for(NODE* node = n1;node != NULL; node = node->next)
    {
        printf("%d -> ",node->data);
    }
    printf("NULL\n");


    NODE* n = n1;
    while(n != NULL)
    {
        printf("%d -> ",n->data);
        n = n->next;
    }
    printf("NULL\n");


    n = n1;
    while(n != NULL)
    {
        NODE* temp = n;
        n = n->next;
        free(temp);
    }
}