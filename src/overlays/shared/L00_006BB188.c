#include "common.h"

extern s32 func_L00_005C9988();
extern s32 func_L00_0061E448();
extern s32 func_L00_006B19F0();
extern s32 func_L00_006B6F40();
extern s32 func_L00_006B9010();
extern void func_L00_006B9780();
extern s32 func_L00_006BAC80();
extern s32 func_L00_006CBC48();
extern s32 func_L00_00700708();
extern s32 D_0021E6B4;
extern s32 D_0021DDB4;

#define F(p, T, o) (*(T *)((u8 *)(p) + (o)))
extern u8 *D_0021DFF0;
typedef struct { u8 pad[0xA8]; u8 fA8[0x10]; } Type1;
extern Type1 D_00171D38;
typedef s32 (*Fn1)(u8 *);

/* Per-frame update of a player-like object: flags, sub-updates, sounds. */
void func_L00_006BB188(u8 *p) {
    s32 v;
    u8 *q;

    if (func_L00_006B6F40(p) || F(p, s32, 0x25CC) == 0x8F) {
        F(p, u8, 0x2664) = F(p, u8, 0x2666) = 1;
    }
    if (func_L00_006B6F40(p) || (v = F(p, s32, 0x25CC)) == 0x31 || v == 0x98 ||
        F(p, s32, 0x25D4) == 3 || v == 0x8F || v == 0x12 ||
        D_0021DDB4 == 1 || D_0021DDB4 == 2) {
        F(p, u8, 0x2668) = 1;
        F(p, u8, 0x2663) = 1;
    } else {
        F(p, u8, 0x2668) = 0;
        F(p, u8, 0x2663) = 0;
    }
    if (F(p, u8 *, 0x2340) != 0) {
        F(p, u8 *, 0x2340)[0x23] = F(p, u8 *, 0x2EF0)[0x23];
    }
    func_L00_006B9010(p);
    if (F(p, s32, 0x2318) != 1) {
        if (D_00171D38.fA8[F(p, s32, 0x2F10)]) {
            F(p, s32, 0x2300) |= 8;
        } else if (F(p, s32, 0x2300) & 8) {
            F(p, s32, 0x2300) &= ~8;
        }
        if (D_0021E6B4 == 1) {
            if (!D_00171D38.fA8[F(p, s32, 0x2F10)]) {
                F(p, s32, 0x2300) |= 0x20;
            } else if (F(p, s32, 0x2300) & 0x20) {
                F(p, s32, 0x2300) &= ~0x20;
            }
        }
    }
    func_L00_006B9780(p, F(p, u8 *, 0x2EF0));
    if (F(p, u8 *, 0x2EF0)[0x31]) {
        func_L00_006B19F0(p);
    }
    if (D_0021E6B4 == 1) {
        if (D_0021DFF0[0x32] && F(D_0021DFF0, s8, 0x34) && F(p, s32, 0x2F14) == 1 &&
            (q = F(p, u8 *, 0x22F0)) != 0) {
            v = (q[0x23] + F(p, u8 *, 0x2EF0)[0x23]) >> 1;
            q[0x23] = v;
            if (F(F(p, u8 *, 0x22F0), s16, 0xBC) == 0x1094) {
                F(F(F(p, u8 *, 0x22F0), u8 *, 0xAC), u8 *, 0x64)[0x23] = v;
            }
        }
        if (D_0021E6B4 == 1 && F(D_0021DFF0, s8, 0x12) && F(p, s32, 0x2EE8) && !F(p, s32, 0x2EF4)) {
            if (!D_00171D38.fA8[F(p, s32, 0x2F10)]) {
                if (F(F(p, u8 *, 0x2F00), s32, 0x1A4) & 2) {
                    func_L00_006CBC48(p, 0);
                }
            } else if (F(F(p, u8 *, 0x2F00), s32, 0x1A4) & 0x20) {
                func_L00_006CBC48(p, 0);
            }
        }
    }
    if (F(p, u8, 0x266C) && F(p, s32, 0x2318) == 0xE && F(p, u8, 0x266D)) {
        func_L00_0061E448(F(F(p, u8 *, 0x14), Fn1, 0x4C)(p), 2);
    }
    if (func_L00_00700708(F(p, s32, 0x26E4), 10) || func_L00_00700708(F(p, s32, 0x26E4), 9)) {
        func_L00_005C9988(0x3324, 0x76F, 0xE10, 2);
    }
    func_L00_006BAC80(p);
}
