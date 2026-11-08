#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u32 unk14;
    u32 unk18;
} Type1;

typedef struct {
    u8 pad[0x3C];
    s32 unk3C;
} Type2;

extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_0049C200(s32 kind, s32 index);
extern void func_0049C328(s32 arg0, s32 arg1, s32 arg2);
extern void func_0049C400(s32 slot, s32 offset, s32 param_a, s32 param_b, s32 mode);
extern void func_0049D170(s32 param_a, s32 param_b, s32 source);
extern void func_0049D1E8(s32 player, s32 slot);
extern void func_0049D308(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004D28E0(s32);
extern void func_004D2988(s32);
extern void func_004D2D30(void);
extern void func_00504F68(s32, s32);
extern s32 func_00505328(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern s32 func_00506120(u32 id, u32 value);

s32 D_0021FB10 = 0;
extern s32 D_00171948[][8];
extern s32 D_003D2A64[];
extern s32 D_003D2A78[5][5];
extern char D_001CDAC0[];
extern s32 D_002219E0;
extern Type1 D_0031B6B0[];

void func_004D2380(void) {
    s32 player;
    Type1 *s;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 tmp;

    player = func_00505B20();
    s = &D_0031B6B0[player];
    if (D_0021FB10 >= 5) {
        D_0021FB10 = 4;
    }
    if (D_0021FB10 < 0) {
        D_0021FB10 = 0;
    }
    s->unk4 = D_0021FB10;
    s->unk0 = 1;
    s->unkC = 0;
    for (k = 0; k < 4; k++) {
        if (D_00171948[k][15] > 0) {
            s->unkC = 1;
            break;
        }
    }
    if (s->unk4 >= 4) {
        s->unkC = 1;
    }
    func_004D2D30();
    func_0049D308(player, 1, D_002219E0);
    func_0049D170(player, 1, func_004A1A60(&D_002219E0, 4));
    func_0049D1E8(player, 1);
    tmp = D_002219E0;
    func_0049C400(player, 3, tmp, func_004A1A60(&D_002219E0, 4), 0);
    func_0049C328(player, 3, 1);
    func_0049C200(player, 3);
    for (i = 0; i < 5; i++) {
        func_004D28E0(i);
    }
    func_004D2988(s->unk4);
    if (s->unkC == 0) {
        func_00505328(func_004A1A60(&D_002219E0, D_003D2A64[0]), 0x80404040);
        for (i = 0; i < 5; i++) {
            func_00505328(func_004A1A60(&D_002219E0, D_003D2A78[4][i]), 0x80404040);
        }
    }
    s->unk14 = func_00499CA0(D_001CDAC0, -1);
    func_005054F8(func_004A1A60(&D_002219E0, 3), 1);
    func_00506120(func_004A1A60(&D_002219E0, 3), s->unk14);
    s->unk18 = func_00499CA0(D_001CDAC0 - 8, -1);
    func_005054F8(func_004A1A60(&D_002219E0, 2), 1);
    func_00506120(func_004A1A60(&D_002219E0, 0xE), s->unk18);
    for (m = 0; m < 5; m++) {
        for (j = 0; j < 5; j++) {
            if (j <= m) {
                func_005054F8(func_004A1A60(&D_002219E0, D_003D2A78[m][j]), 0x7546);
            } else {
                func_00504F68(func_004A1A60(&D_002219E0, D_003D2A78[m][j]), 0);
            }
        }
    }
    s->unk8 = 1;
}
