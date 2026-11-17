/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern void func_0011A518(void *, s32, s32);

typedef struct { u8 f0[4]; s16 f4; u8 f6[2]; u8 f8[8]; s32 f10; u8 f14[8]; s32 f1c; u8 f20[4]; s16 f24; s16 f26; u8 f28[0xB8]; u8 fe0[0x20]; s32 f100; u8 f104[8]; u8 f10c[4]; } E110;
typedef struct { u64 a; u64 b; } __attribute__((packed)) Unal16;
typedef struct { u8 pad0[0x40]; s32 n; u8 pad44[0x20]; s32 f64; u8 pad68[0x20]; E110 e[1]; } S;
extern S D_1BCC28[];

// Returns 1 if an entry matches the halfword at 0x4 of the input, otherwise claims and clears a free entry.
s32 func_00152F00(u8 *arg0) {
    s32 i;
    E110 *e;

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
        D_1BCC28[0].f64 = 1;
        e->f100 = 0;
        func_0011A518(e->f104, 0, 8);
        e->f26 = 0;
        e->f24 = 0;
        func_0011A518(e->fe0, 0, 0x20);
        return 0;
    }
    return 1;
}
