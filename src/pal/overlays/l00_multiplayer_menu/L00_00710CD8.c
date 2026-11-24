#include "common.h"
#include "pal/global_002234A4.h"

typedef struct Ctx {
    u8 pad0[0x44];
    s32 x44;
    u8 pad48[0x1C];
    char *x64;
} Ctx;

typedef struct Slot {
    u8 used;
    u8 pending;
    u8 pad2[0x2];
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
} Slot;

typedef struct Req {
    u16 x0;
    u8 pad2[0x13];
    char x15[0x13];
    u8 pad28[0x8];
} Req;

extern Slot D_003F3F78[16];
extern u8 D_0022333C;
extern u16 D_00220B98[];
extern u8 D_0015D800[];
extern s32 func_L00_007755D0(s32, s32);
extern s32 func_L00_00775438(s32, s32, s32, s32, s32, s32 *);
extern char *func_0011A9EC(char *, char *);
extern s32 func_01ED7848(void *, void *, s32);
extern void func_0015A080(void);

// slot sync
s32 func_L00_00710CD8(void) {
    Req r;
    s32 id;
    s32 ok;
    s32 i;
    s32 j;
    s32 k;

    ok = 1;
    id = ((Ctx *)D_002234A4)->x44;
    for (j = 1; j < 16 && ok != 0; j++) {
        if (D_003F3F78[j].pending != 0) {
            ok = func_L00_007755D0(id, D_003F3F78[j].x4);
            if (ok != 0) {
                D_003F3F78[j].pending = 0;
            }
        }
    }
    i = 1;
    if (ok != 0) {
        for (; i < 16 && ok != 0; i++) {
            if (D_003F3F78[i].used != 0) {
                D_003F3F78[i].pending = func_L00_00775438(id, i, D_003F3F78[i].xC, D_003F3F78[i].x10, D_003F3F78[i].x8, &D_003F3F78[i].x4);
                ok = D_003F3F78[i].pending;
            }
        }
    }
    D_0022333C = 0;
    r.x0 = D_00220B98[0];
    func_0011A9EC(r.x15, ((Ctx *)D_002234A4)->x64);
    func_01ED7848(&r, D_0015D800, 0);
    for (k = 0; D_0022333C == 0 && k < 200; k++) {
        func_0015A080();
    }
    return ok;
}
