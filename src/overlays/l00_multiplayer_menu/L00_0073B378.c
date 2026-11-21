#include "common.h"

typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    u8 pad20[0x500 - 0x20];
    s32 f500[0x6E];
    s16 f6B8[0x84];
    s32 f7C0[4];
} Type1;
extern s32 func_0011AB04(u8 *);
extern u8 *D_0021DFE8;
extern Type1 D_1E0D78[];

/* Compare two player slots for sorting: named first, then flags, team key, score, then tie value. */
s32 func_L00_0073B378(u8 *arg0, s32 a, s32 b) {
    u8 *p;
    u8 *flags;
    s32 key;
    s32 sa;

    if (func_0011AB04(arg0 + (a * 16 + 0x260)) == 0 && func_0011AB04(arg0 + (b * 16 + 0x260)) == 0) {
        return 0;
    }
    if (func_0011AB04(arg0 + (a * 16 + 0x260)) == 0) {
        return 1;
    }
    if (func_0011AB04(arg0 + (b * 16 + 0x260)) == 0) {
        return 0;
    }
    p = D_0021DFE8;
    if (p != 0) {
        flags = p + 0x104;
        if (flags[a] == 0xFF) {
            return 1;
        }
        if (flags[b] == 0xFF) {
            return 0;
        }
    }
    if (D_1E0D78->f18 != 0) {
        key = D_1E0D78->f1C;
        if (key != -1) {
            sa = D_1E0D78->f500[a];
            if (sa != key) {
                if (D_1E0D78->f500[b] == key) {
                    return 1;
                }
            } else if (D_1E0D78->f500[b] != sa) {
                return 0;
            }
        }
    }
    if (D_1E0D78->f7C0[a] < D_1E0D78->f7C0[b]) {
        return 1;
    }
    if (D_1E0D78->f7C0[a] == D_1E0D78->f7C0[b] && D_1E0D78->f6B8[a] > D_1E0D78->f6B8[b]) {
        return 1;
    }
    return 0;
}
