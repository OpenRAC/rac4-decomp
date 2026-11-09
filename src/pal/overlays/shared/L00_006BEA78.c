#include "common.h"

extern s32 func_0045E288();
extern s32 func_L00_00621580();
extern s32 func_L00_006B52D0();
extern s32 func_00516810();
extern s32 func_L00_006BC8F0();
extern void func_L00_006BD060();
extern s32 func_L00_006BE570();
extern s32 func_00523DF0();
extern s32 func_0054A308();
extern s32 D_0021E734;
extern s32 D_0021DDB4;

#define F(p, T, o) (*(T *)((u8 *)(p) + (o)))
extern u8 *D_0021E078;
typedef struct { u8 pad[0xA8]; u8 fA8[0x10]; } Type1;
extern Type1 D_00171DB8;
typedef s32 (*Fn1)(u8 *);

void func_L00_006BEA78(u8 *p) {
    s32 v;
    u8 *q;

    if (func_00516810(p) || F(p, s32, 0x25CC) == 0x8F) {
        F(p, u8, 0x2664) = F(p, u8, 0x2666) = 1;
    }
    if (func_00516810(p) || (v = F(p, s32, 0x25CC)) == 0x31 || v == 0x98 ||
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
    func_L00_006BC8F0(p);
    if (F(p, s32, 0x2318) != 1) {
        if (D_00171DB8.fA8[F(p, s32, 0x2F10)]) {
            F(p, s32, 0x2300) |= 8;
        } else if (F(p, s32, 0x2300) & 8) {
            F(p, s32, 0x2300) &= ~8;
        }
        if (D_0021E734 == 1) {
            if (!D_00171DB8.fA8[F(p, s32, 0x2F10)]) {
                F(p, s32, 0x2300) |= 0x20;
            } else if (F(p, s32, 0x2300) & 0x20) {
                F(p, s32, 0x2300) &= ~0x20;
            }
        }
    }
    func_L00_006BD060(p, F(p, u8 *, 0x2EF0));
    if (F(p, u8 *, 0x2EF0)[0x31]) {
        func_L00_006B52D0(p);
    }
    if (D_0021E734 == 1) {
        if (D_0021E078[0x32] && F(D_0021E078, s8, 0x34) && F(p, s32, 0x2F14) == 1 &&
            (q = F(p, u8 *, 0x22F0)) != 0) {
            v = (q[0x23] + F(p, u8 *, 0x2EF0)[0x23]) >> 1;
            q[0x23] = v;
            if (F(F(p, u8 *, 0x22F0), s16, 0xBC) == 0x1094) {
                F(F(F(p, u8 *, 0x22F0), u8 *, 0xAC), u8 *, 0x64)[0x23] = v;
            }
        }
        if (D_0021E734 == 1 && F(D_0021E078, s8, 0x12) && F(p, s32, 0x2EE8) && !F(p, s32, 0x2EF4)) {
            if (!D_00171DB8.fA8[F(p, s32, 0x2F10)]) {
                if (F(F(p, u8 *, 0x2F00), s32, 0x1A4) & 2) {
                    func_00523DF0(p, 0);
                }
            } else if (F(F(p, u8 *, 0x2F00), s32, 0x1A4) & 0x20) {
                func_00523DF0(p, 0);
            }
        }
    }
    if (F(p, u8, 0x266C) && F(p, s32, 0x2318) == 0xE && F(p, u8, 0x266D)) {
        func_L00_00621580(F(F(p, u8 *, 0x14), Fn1, 0x4C)(p), 2);
    }
    if (func_0054A308(F(p, s32, 0x26E4), 10) || func_0054A308(F(p, s32, 0x26E4), 9)) {
        func_0045E288(0x3324, 0x76F, 0xBB8, 2);
    }
    func_L00_006BE570(p);
}
