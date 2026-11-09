#include "common.h"

typedef struct {
    s32 pad0;
    s32 unk4;
    s32 unk8;
    s32 padC[4];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 pad2C[8];
    u8 pad4C[3];
    u8 unk4F;
    u8 unk50;
    u8 pad51[3];
    s32 unk54;
    s32 pad58[2];
    s32 unk60;
} Type004D31F0;

typedef struct {
    s32 pad0[3];
    s32 unkC;
    s32 unk10;
} Type23AB00;

extern s32 func_00138D70(s32 arg0);
extern void func_004D31A0(void);
extern void func_004D3748(s32 arg0);
extern void func_004E7638(void);
extern void func_004E7830(s32 mask);
extern void func_004E7D90(s32 arg0, s32 arg1, s32 arg2);

extern Type004D31F0 D_003D9BE0;
extern Type23AB00 D_0023AB00[];
extern s32 D_0021EDE8;
extern s32 D_0021EDEC;
extern s32 D_00221E28;
extern s32 D_001D3F44[];
extern s32 D_001DFCF4[];
extern s32 D_0021DA34;
extern s32 D_002211CC;

void func_004D31F0(void) {
    if (D_003D9BE0.unk4F == 0 || D_003D9BE0.unk50 != 0) {
        s32 k = 0x30000;
        func_004E7830(1);
        func_00138D70(0);
        D_002211CC++;
        D_003D9BE0.unk60 = D_0021DA34;
        D_003D9BE0.unk4 = D_0023AB00[0].unkC + k;
        D_003D9BE0.unk8 = D_0023AB00[0].unk10 + k;
        D_00221E28 = k;
        func_004D31A0();
        D_003D9BE0.unk1C = D_003D9BE0.unk4 + 0xC000;
        D_003D9BE0.unk20 = D_003D9BE0.unk8 + 0xC000;
        D_003D9BE0.unk24 = D_003D9BE0.unk1C + k;
        D_003D9BE0.unk28 = D_003D9BE0.unk20 + 0xE0000;
        D_003D9BE0.unk4 = D_003D9BE0.unk24 + 0xD6400;
        D_003D9BE0.unk8 = D_003D9BE0.unk28 + 0x61C00;
        func_004D3748(1);
        D_0021EDE8 = 0x2000;
        D_0021EDEC = 0x1000;
        func_004E7638();
        func_004E7D90(D_003D9BE0.unk20, D_001DFCF4[0], D_001D3F44[0] << 11);
    }
    D_003D9BE0.unk4F = 0;
    D_003D9BE0.unk50 = 0;
    D_003D9BE0.unk54 = 0;
}
