#include "common.h"

extern u8 D_1F87F0[];
extern u8 D_0021FBE0[];
typedef struct { u64 q0; u64 q1; } __attribute__((packed)) Type2;

// Copies the 16-byte block at D_0021FBE0 to the stack and counts its four words whose record in D_1F87F0 has a nonzero flag.
s32 func_004D6DD0(void) {
    Type2 copy;
    int *p;
    int n;
    int w;
    int count;
    int next;
    int stride;

    copy = *(Type2 *)D_0021FBE0;
    stride = 12;
    count = 0;
    p = (int *)&copy;
    n = 3;
    do {
        w = *p;
        next = count + 1;
        p++;
        n--;
        count = (D_1F87F0[w * stride + 9] != 0) ? next : count;
    } while (n >= 0);
    return count;
}
