#include "common.h"

typedef struct Ent {
    u16 x0;
    u8 pad2[2];
    u32 x4;
    u32 x8;
} Ent;

typedef struct Tbl {
    u8 pad0[0xC];
    u16 xC;
    u8 padE[2];
} Tbl;

typedef struct Q {
    s32 x0;
} Q;

extern s32 D_0021EC98;
extern u32 D_0021DAF0;
extern s32 D_0021E298;
extern Q D_00222648;
extern s32 D_00222468;
extern Tbl *D_00222464;
s32 D_00222460 = 0;
extern s32 D_002226C4;
extern Ent D_001F1480[];

extern s32 func_0048ACE8(Q *q, s32 a, void *buf);
extern s32 func_0048ABD8(Q *q, s32 a, s32 b, s32 c, s32 d);
extern s32 func_0045EB78(s32 a);

// Queues a request for entry b of the table at D_001F1480 when the queue at D_00222648 is free, then updates that entry's counters.
s32 func_0045E478(s16 a, s16 b) {
    u8 buf[4];
    Ent *e;
    s32 f;
    s32 r;
    u32 g;

    if (D_0021EC98 > 0) {
        if (func_0048ACE8(&D_00222648, D_00222468, buf) != 0) {
            return 0;
        }
        if (D_002226C4 - D_00222460 < 0x33) {
            return 0;
        }
        e = &D_001F1480[b];
        if (e->x0 != 0) {
            return 0;
        }
        f = D_00222464[func_0045EB78(a)].xC & 0x7FFF;
        r = func_0048ABD8(&D_00222648, f, 2, 0, D_00222464[func_0045EB78(a)].xC >> 15);
        D_00222468 = r;
        if (func_0048ACE8(&D_00222648, r, buf) != 0) {
            D_00222460 = D_002226C4;
            if (b >= 0) {
                if (e->x0 < 0xFFFF) {
                    e->x0 = e->x0 + 1;
                }
                g = D_0021DAF0;
                if (e->x4 < g) {
                    e->x4 = g;
                }
                e->x8 = e->x8 | (1 << ((D_0021E298 - 1) % 20)) | 0x80000000;
            }
            return 1;
        }
    }
    return 0;
}
