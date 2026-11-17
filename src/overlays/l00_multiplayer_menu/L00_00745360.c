#include "common.h"

extern s32 func_0011AB04(u8 *);

typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    u8 pad20[0x4E0];
    s32 f500[10];
    u8 pad528[0x190];
    s16 f6B8[10];
    u8 pad6CC[0xF4];
    s32 f7C0[10];
} Type1;

typedef struct {
    u8 pad0[0x260];
    u8 f260[10][16];
} Type2;

extern Type1 D_1E0D78[];

/* orders two slots: 1 if the first ranks before the second, else 0 */
s32 func_L00_00745360(Type2 *arg0, s32 arg1, s32 arg2) {
    s32 a;
    s32 b;
    if (func_0011AB04(arg0->f260[arg1]) == 0 && func_0011AB04(arg0->f260[arg2]) == 0) {
        return 0;
    }
    if (func_0011AB04(arg0->f260[arg1]) == 0) {
        return 1;
    }
    if (func_0011AB04(arg0->f260[arg2]) != 0) {
        if (D_1E0D78->f18 != 0 && D_1E0D78->f1C != -1) {
            if (D_1E0D78->f500[arg1] != D_1E0D78->f1C) {
                if (D_1E0D78->f500[arg2] == D_1E0D78->f1C) {
                    return 1;
                }
            } else {
                if (D_1E0D78->f500[arg2] != D_1E0D78->f500[arg1]) {
                    return 0;
                }
            }
        }
        a = D_1E0D78->f7C0[arg1];
        b = D_1E0D78->f7C0[arg2];
        if (a < b) {
            return 1;
        }
        if (a != b) {
            return 0;
        }
        if (D_1E0D78->f6B8[arg1] > D_1E0D78->f6B8[arg2]) {
            return 1;
        }
    }
    return 0;
}
