#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "data_structures/linked_list.h"
void add(){}
int main(void)
{
    char str[12+1];
    char* n = gets_s(str,13);
    if(n==NULL)
    {
        perror("STR: ");
    }else{
    printf("%s\n",str);
    printf("%p ----- %p\n",str,n);

    for(int i = 0; i < 13;i++)
    {
        printf("%X  ",str[i]);
    }

    NODE node;
}}
