#include "common.h"

typedef struct {
    u8 pad[0x2314];
    s32 f2314;
    s32 f2318;
} Type1;

/* The word at +0x2318 when the state at +0x2314 is 2, else -1. */
s32 func_L00_006B6EF0(Type1 *e) {
    if (e->f2314 == 2) {
        return e->f2318;
    }
    return -1;
}
