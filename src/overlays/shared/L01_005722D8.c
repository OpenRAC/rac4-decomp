#include "common.h"

/* Clear the five eight-entry arrays and the trailing byte, storing T1 in the
   short array. */
s32 func_L01_005722D8(char *p, s32 a1, s32 a2, s32 a3, s32 a4, s32 t1)
{
    u16 *q4 = (u16 *)(p + 0x80);
    s32 *q3 = (s32 *)(p + 0x60);
    s32 *q2 = (s32 *)(p + 0x40);
    s32 *q1 = (s32 *)(p + 0x20);
    s32 *q0 = (s32 *)p;
    s32 n = 7;

    do {
        *q0 = 0;
        n--;
        *q1 = 0;
        q0++;
        *q2 = 0;
        q1++;
        *q3 = 0;
        q2++;
        *q4 = t1;
        q3++;
        q4++;
    } while (n >= 0);
    *(u8 *)(p + 0x91) = 0;
    return 1;
}
