#include <stdio.h>
#include "sort.h"

int main(void)
{
    int num[] = {5,4,3,2,1};

    for(int i = 0; i < 5;i++)
    {
        printf("%d",num[i]);
    }
    printf("\n");
    InsertionSort(num,5,0);

    for(int i = 0; i < 5;i++)
    {
        printf("%d",num[i]);
    }
}