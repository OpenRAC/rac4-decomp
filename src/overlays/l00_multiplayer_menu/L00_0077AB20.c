#include "common.h"

typedef struct Type1 {
    u8 b[16];
} Type1;

extern Type1 D_1E0D78[];
extern Type1 D_172160[];

/* Returns 1 if either per-slot byte flag is set. */
s32 func_L00_0077AB20(s32 arg0) {
    s32 r = 0;

    if (D_1E0D78[arg0].b[0x410] != 0 || D_172160[arg0].b[0x803] != 0) {
        r = 1;
    }
    return r;
}
