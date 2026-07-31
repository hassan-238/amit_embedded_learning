#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define CLR_BIT(reg, bit) (reg &= (~(1 << bit))) // change to zero
#define TOG_BIT(reg, bit) (reg ^= (1 << bit))    // toggle if zero then 1 if 1 then zero
#define GET_BIT(reg, bit) ((reg >> bit) % 2 == 1)

// 01011111
// value = x
//
// challenges
#define ROR_BIT(reg) (reg = ((reg >> 1) | (GET_BIT(reg, 0) << (sizeof(reg) * 7))))                      // rotate left
#define ROL_BIT(reg) (reg = ((reg << 1) | (GET_BIT(reg, 7))))                                           // rotate right
#define ASS_BIT(reg, bit, value) (reg = ((value % 2 == 1) ? (SET_BIT(reg, bit)) : (CLR_BIT(reg, bit)))) // ASSIGN BIT

#define PRINT_BIN(reg)                                 \
    {                                                  \
        for (int i = sizeof(reg) * 8 - 1; i >= 0; i--) \
        {                                              \
            printf("%d", (reg >> i) & 1);              \
        }                                              \
        printf("\n");                                  \
    }

#endif