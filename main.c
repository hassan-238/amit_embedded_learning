#include <stdio.h>

int main(void)
{
    #ifdef DEBUG
        printf("HELLOW WORLD!\n");
    #endif
        printf("Hello %s %d %s",__FILE__, __LINE__, __DATE__);
}