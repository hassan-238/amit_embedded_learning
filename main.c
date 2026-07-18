#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[2] = {1,2};
    int * ptr = arr;
    printf("%d",++*ptr);
    printf("%d",*ptr);
}
