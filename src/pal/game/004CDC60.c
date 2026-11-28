#include "common.h"

extern s32 func_0047DBB0(s32);
extern s32 func_004CDE78(s32);
extern s32 D_0030EA50[];

s32 D_00221A14 = 0;

/* Lazily initialise the eight-entry category map. */
s32 func_004CDC60(s32 arg0)
{
    s32 value;
    s32 two;
    s32 three;
    s32 six;
    s32 seven;
    s32 eight;
    s32 nine;
    s32 one;
    s32 *table;

    if (arg0 < 8) {
        value = 4;
        if (func_0047DBB0(5) != 0) {
            value = 5;
        }
        if (D_00221A14 == 0) {
            two = 2;
            three = 3;
            six = 6;
            seven = 7;
            eight = 8;
            nine = 9;
            one = 1;
            table = D_0030EA50;
            table[7] = nine;
            table[2] = three;
            table[3] = value;
            table[4] = six;
            table[5] = seven;
            table[6] = eight;
            table[1] = two;
            D_0030EA50[0] = one;
            D_00221A14 = one;
        }
        return D_0030EA50[arg0];
    }
    return func_004CDE78(arg0);
}
