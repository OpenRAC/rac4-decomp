#include "common.h"

typedef struct Ent {
    s32 off;
    s32 size;
} Ent;

typedef struct Table {
    u8 pad0[0xCC10];
    Ent files[0x80];
} Table;

typedef struct Req {
    u8 pad0[0x4];
    s32 x4;
    s32 x8;
    u8 padC[0x4];
    u8 x10;
    u8 x11;
    u8 x12;
    u8 x13;
    u8 pad14[0x7];
    u8 x1B;
    u8 pad1C[0x8];
    s32 x24;
} Req;

extern Table D_001C20C0;
extern s32 D_0024005C[];
extern Req D_00171228;
extern void func_L00_00699918(void);

// Queues a request for entry id of the table at D_001C20C0 (if the entry is
// valid, the system is ready and no request is pending) and, unless noWait is
// set, waits until it completes. Returns 1 if queued, 0 otherwise.
s32 func_L00_00699C48(u32 id, s32 noWait)
{
    s32 ready = D_0024005C[0];
    Req *r;

    if (id >= 0x80) {
        return 0;
    }
    if (D_001C20C0.files[id].off <= 0 || D_001C20C0.files[id].size <= 0) {
        return 0;
    }
    if (ready == 0) {
        return 0;
    }
    r = &D_00171228;
    if (r->x12 != 0) {
        return 0;
    }
    r->x4 = id;
    r->x12 = 1;
    r->x24 = 1;
    r->x8 = 0;
    r->x10 = 0;
    r->x11 = 0;
    r->x13 = 0;
    r->x1B = 0;
    if (!noWait) {
        do {
            func_L00_00699918();
        } while (D_00171228.x12 != 0);
    }
    return 1;
}
