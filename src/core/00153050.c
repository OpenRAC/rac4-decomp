/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct { u8 f0[4]; s16 f4; u8 f6[2]; u8 f8[8]; s32 f10; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24; u8 f28[0x14]; s16 f3c; u8 f3e[0x2a]; } E68;
typedef struct { u64 a; u64 b; } __attribute__((packed)) Unal16;
typedef struct { u8 pad0[0x44]; s32 n; u8 pad48[0x20]; s32 f68; u8 pad6C[0x45C]; E68 e[1]; } S;
extern S D_1BCC28[];

// Returns 1 if an entry matches the halfword at 0x4 of the input, otherwise claims a free entry.
s32 func_00153050(u8 *arg0) {
    s32 i;
    E68 *e;

    for (i = 0; i < D_1BCC28[0].n; i++) {
        if (D_1BCC28[0].e[i].f4 == *(s16 *)(arg0 + 4)) {
            return 1;
        }
    }
    for (i = 0; i < D_1BCC28[0].n; i++) {
        if (D_1BCC28[0].e[i].f4 == -1) {
            break;
        }
    }
    if (i < D_1BCC28[0].n) {
        e = &D_1BCC28[0].e[i];
        *(Unal16 *)e = *(Unal16 *)arg0;
        e->f1c = 1;
        e->f10 = 0;
        D_1BCC28[0].f68 = 1;
        e->f20 = 0;
        e->f24 = 0;
        e->f3c = 0;
        return 0;
    }
    return 1;
}
