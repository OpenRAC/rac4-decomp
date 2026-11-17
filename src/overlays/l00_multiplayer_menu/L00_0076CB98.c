#include "common.h"

extern void func_L00_0076D2A8(void *arg0, s32 arg1);

typedef struct T1 {
    s32 f0;
    char *f4;
    char *f8;
    s32 fC;
} T1;

// Initializes an array of 0xD8-byte records, linking each to the next, and terminates the list.
void func_L00_0076CB98(T1 *arg0) {
    s32 i;
    char *p;

    arg0->fC = 0;
    for (i = 0; i < arg0->f0; i++) {
        p = arg0->f4 + i * 0xD8;
        func_L00_0076D2A8(p, i);
        *(s32 *)(p + 0xD4) = i * 0xD8 + (s32)arg0->f4 + 0xD8;
    }
    *(s32 *)(arg0->f4 + arg0->f0 * 0xD8 - 4) = 0;
    arg0->f8 = arg0->f4;
}
