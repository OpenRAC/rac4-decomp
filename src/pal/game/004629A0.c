#include "common.h"

typedef struct Ent {
    s32 off;
    s32 size;
} Ent;

typedef struct Table {
    u8 pad0[0x9AC];
    s32 x9AC;
    u8 pad9B0[0x140];
    Ent groupA[12];
    Ent groupB[8];
    Ent groupC[8];
} Table;

extern u8 D_001DFCE0[];
extern s32 D_001DFD70[];
extern s32 D_00221F18[];
extern s32 D_00221F2C;
extern Table D_001C20C0;
extern void func_004E8758(s32);
extern void func_0048A6E0(s32);
extern void func_00163550(s32);
extern s32 func_001638B0(s32, s32, s32, s32, s32, s32, s32);
extern void func_004626E0(s32, s32, s32, void *, void *);

// Selects entry id of one group in the table at D_001C20C0 (the three twins
// 004628C0, 004629A0 and 00462A80 each handle one group). Does nothing if it
// is already selected; otherwise records it and passes its data to
// func_001638B0 and func_004626E0.
void func_004629A0(s32 id)
{
    u8 *t;
    s32 buf;

    t = D_001DFCE0;
    if (*(s32 *)(t + 0x58) == id) {
        return;
    }
    *(s32 *)(t + 0x58) = id;
    func_004E8758(1);
    buf = D_00221F18[1 - D_00221F2C];
    func_0048A6E0(1);
    func_00163550(1);
    func_001638B0(0, buf, D_001C20C0.groupB[id].off + D_001C20C0.x9AC, D_001C20C0.groupB[id].size, 0, 0, 0);
    func_004626E0(D_001DFD70[15], D_001DFD70[9], buf, t + 0x5C, t + 0x60);
}
