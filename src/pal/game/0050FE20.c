#include "common.h"

typedef struct {
    char p0[0x34];
    s32 f34;
    s32 f38;
    char p3C[4];
    u16 f40;
    char p42[2];
    u16 f44;
    char p46[8];
    u16 f4E;
    char p50;
    u8 f51;
    u8 f52;
} Type1;
typedef struct {
    char p0[0x40];
    Type1 *f40;
} Type2;

/* Clears playback state, preserving the flagged initial index. */
void func_0050FE20(Type2 *a)
{
    u16 x = 0;
    a->f40->f51 = 0;
    if (a->f40->f40 & 8)
        x = a->f40->f44;
    a->f40->f4E = x;
    a->f40->f52 = 0;
    a->f40->f38 = 0;
    a->f40->f34 = 0;
}
