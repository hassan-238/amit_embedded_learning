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
    MergeSort(num,5,1);

    for(int i = 0; i < 5;i++)
    {
        printf("%d",num[i]);
    }

    printf("\n");
    MergeSort(num,5,0);

    for(int i = 0; i < 5;i++)
    {
        printf("%d",num[i]);
    }


    int num2[] = {6,5,4,3,2,1};

    for(int i = 0; i < 56;i++)
    {
        printf("%d",num2[i]);
    }
    printf("\n");
    MergeSort(num2,6,1);

    for(int i = 0; i < 6;i++)
    {
        printf("%d",num2[i]);
    }

    printf("\n");
    MergeSort(num2,6,0);

    for(int i = 0; i < 6;i++)
    {
        printf("%d",num2[i]);
    }
}