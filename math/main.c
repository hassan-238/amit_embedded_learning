#include <stdio.h>
#include "bitmath.h"
#include <stdlib.h>

typedef unsigned char u8;

int main(void)
{
    u8 bits = 0b01110011;
    
   PRINT_BIN(bits);

    printf("SET bit index 3: ");
    SET_BIT(bits,3);    
    PRINT_BIN(bits);

    printf("CLR bit index 5: ");
    CLR_BIT(bits,5); 
   PRINT_BIN(bits);

    printf("TOG bit index 2: ");
    TOG_BIT(bits,2); 
    PRINT_BIN(bits);
    TOG_BIT(bits,2); 
    PRINT_BIN(bits);

    int value = 0;
    printf("GET bit index 4: ");
    value = GET_BIT(bits,2); 
    printf("%d\n",value);

    printf("\n\n");
    
    printf("ROR BIT: ");
    PRINT_BIN(bits);
    ROR_BIT(bits);
    PRINT_BIN(bits);

    printf("ROL BIT: ");
    PRINT_BIN(bits);
    ROL_BIT(bits);
    PRINT_BIN(bits);

   
}