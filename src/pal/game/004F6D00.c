#include "common.h"

extern u8 D_003289E8[];
typedef struct {
    u8 pad0[0x74];
    s32 x74;
    u8 pad78[8];
    s16 x80;
    u8 pad82[0x16E];
    u8 *x1F0;
} Hud;

extern Hud D_00237100;
extern s32 D_003DC000[];
extern u8 *D_002215E0;
extern s32 D_002215E8;
extern void func_004F45A0(void);
extern s32 func_004F6080(void);
extern void func_004F63D0(void);
extern s32 func_004F5F08(void);
extern void func_004F6030(s32);
extern void func_004F6B28(void);
extern void func_004F65B0(void (*)(void));
extern void func_004F6088(void);
extern void func_004F68E8(void);
extern void func_004F60A8(s32, s32, s32, s32);

// If the byte at D_003289E8+0x50 is set, runs a setup sequence once (until
// +0x51 is set); calls func_004F60A8 with values from D_00237100 and, when +0x51 is
// set, scales byte 7 of each 0x40-byte entry of D_002215E0 by 0x80 - [[D_00237100+0x1F0]+0x69].
void func_004F6D00(s32 arg) {
    s32 v;
    s32 a;
    u8 *q;
    u8 *end;

    if (D_003289E8[0x50] != 0) {
        func_004F45A0();
        if (func_004F6080() == 1) {
            func_004F63D0();
        }
        if (D_003289E8[0x51] == 0) {
            if (func_004F6080() > 0 && arg != 0) {
                D_003289E8[0x51] = 1;
                v = D_003DC000[0];
            } else {
                v = func_004F5F08();
            }
            func_004F6030(v);
            func_004F65B0(func_004F6B28);
            func_004F6088();
            func_004F68E8();
        }
    }
    if (D_003289E8[0x51] != 0) {
        func_004F60A8(D_00237100.x74, D_00237100.x80 + 1, 12, 0);
    } else {
        func_004F60A8(D_00237100.x74, D_00237100.x80, 12, 12);
    }
    if (D_003289E8[0x51] != 0) {
        a = 0;
        if (D_00237100.x1F0 != NULL) {
            a = 0x80 - D_00237100.x1F0[0x69];
        }
        end = D_002215E0 + D_002215E8 * 0x40 + 0x40;
        for (q = D_002215E0; q < end; q += 0x40) {
            if (!(q[1] & 0x80)) {
                q[7] = (q[7] * a) >> 7;
            }
        }
    }
}
