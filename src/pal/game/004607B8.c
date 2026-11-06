#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

extern void func_00126F60(Type1 *, s32);

/* Process a pair of buffers in bounded chunks. */
void func_004607B8(s32 arg0, s32 arg1, s32 arg2)
{
    s32 remaining = arg2;
    s32 offset = 0;
    s32 maximum = 0xFFFF0;
    s32 chunk;
    Type1 params;
    do {
        chunk = maximum < remaining ? maximum : remaining;
        params.f0 = arg0 + offset;
        params.f4 = arg1 + offset;
        params.f8 = chunk;
        params.fC = 0;
        func_00126F60(&params, 1);
        remaining -= chunk;
        offset += chunk;
    } while (remaining != 0);
}
