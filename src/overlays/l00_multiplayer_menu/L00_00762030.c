#include "common.h"

extern void func_L00_007647B0(s32);

typedef struct Part Part;
typedef struct {
    u8 pad0[0x20];
    void (*setMode)(Part *, s32, s32);
} PartVt;
struct Part {
    u8 pad0[0x4];
    s32 state;
    u8 pad8[0x58 - 0x8];
    PartVt *vt;
};

typedef struct {
    u8 pad0[0xB0];
    Part *parts[96];
    s32 cur;
} Menu;

s32 func_L00_00762030(Menu *m, s32 dir, s32 lo, s32 hi) {
    s32 delta;
    s32 next;
    s32 state;

    delta = 1;
    if (dir == 1) {
        delta = -1;
    } else if (dir != 2) {
        delta = 0;
    }
    next = m->cur + delta;
    if (next >= lo && next <= hi) {
        state = m->parts[next]->state;
        if (state != 0) {
            if (state != 1) {
                func_L00_007647B0(3);
                m->parts[m->cur]->vt->setMode(m->parts[m->cur], 2, 0);
                m->cur = next;
                goto out;
            }
        }
    }
    if (next < lo || next > hi) {
        func_L00_007647B0(4);
    } else {
        state = m->parts[next]->state;
        if (state != 0) {
            if (state != 1) {
                goto out;
            }
        }
        func_L00_007647B0(4);
    }
out:
    return 1;
}
