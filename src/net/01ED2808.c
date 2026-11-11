/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct {
    u8 pad[0x14];
    s32 (*f14)(s32);
} Type1;

extern s32 func_01EA42D8(s32);
extern Type1 *D_00167F3C;

s32 func_01ED2808(u8 *arg0) {
    s32 v;

    if (arg0 == NULL) {
        return 0x17;
    }
    v = *(s32 *)(arg0 + 0x474);
    if (v == 0) {
        return 0xA;
    }
    return func_01EA42D8(D_00167F3C->f14(v));
}
