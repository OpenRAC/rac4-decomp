#include "common.h"

typedef struct E_004C33D0 {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x58 - 0x1C];
    s8 unk58[10];
    u8 pad62[0x74 - 0x62];
} E_004C33D0;

typedef struct T_004C33D0 {
    s32 unk0;
    s32 unk4;
} T_004C33D0;

extern E_004C33D0 D_0030B7F8[];
extern s32 D_00221888;
extern T_004C33D0 D_003D22E0[];
extern s32 D_003D2320[];
extern T_004C33D0 D_003D2248[];
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505328(s32, u32);
extern s32 func_00505B20(void);

void func_004C33D0(void) {
    E_004C33D0 *e;
    s32 i;

    e = &D_0030B7F8[func_00505B20()];
    func_00505328(func_004A1A60(&D_00221888, D_003D22E0[e->unk18].unk0), 0x80808080);
    func_00505328(func_004A1A60(&D_00221888, D_003D2320[e->unk18]), 0x80808080);
    for (i = 0; i < 10; i++) {
        if (e->unk58[i] == e->unk18 + 1) {
            func_00505328(func_004A1A60(&D_00221888, D_003D2248[i].unk0), 0x80808080);
        }
    }
}
