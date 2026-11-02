#include "common.h"

typedef struct Type1 {
    char pad[0x74];
    u16 f74;
} Type1;

/* Place the selected bit in the appropriate object. */
void func_004CE550(Type1 *first, Type1 *second, u32 bit)
{
    if (bit < 5 || !second) {
        first->f74 = 1 << bit;
        if (second)
            second->f74 = 0;
    } else {
        bit -= 5;
        if (bit < 3) {
            first->f74 = 0;
            second->f74 = 1 << bit;
        }
    }
}
