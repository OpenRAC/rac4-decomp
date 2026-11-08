/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC];
    u32 fC;
};

s32 func_01ED8EC8(Type1 *arg0) {
    u32 v;
    u32 x;

    if (arg0 == NULL) {
        return 0;
    }
    v = arg0->fC;
    x = (v & 0x55555555) + ((v >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
    x = (x & 0xFFFF) + (x >> 16);
    return x & 0xFFFF;
}
