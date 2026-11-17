/* cflags: -fno-opt-stack */
#include "common.h"

extern void func_00147AE0(void *arg0);
extern void func_00147AF0(void *arg0);
extern s32 func_00147638(void);
extern void func_0014F450(f32, s32, f32, s32, f32, s32, s32, s32, s32, s32, s32);
extern void func_00150648(void *, void *, void *, void *, void *, s32, s32, s32, void *, void *, s32, s32, s32, void *, void *, s32, s32, s32);
extern s32 D_0016F750[];

/* Checks three linked objects and their three planes, links them, runs the setup calls and returns 0, or the status code of the first failed check. */
s32 func_001511F0(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    s64 k0;
    s64 k1;
    u8 t18;
    u8 u18;
    u16 w0;
    u16 w1;
    f32 sp50;
    s32 sp54;
    f32 sp58;
    s32 sp5C;
    f32 sp60;
    s32 sp64;

    if (arg0 == 0) {
        return 0x17D4;
    }
    k0 = *(s64 *)arg0;
    if (k0 != 0xFACE) {
        return 0x17D4;
    }
    t18 = *((u8 *)arg0 + 0x18);
    if (t18 != 0xB) {
        return 0x17E3;
    }
    if (arg1 == 0) {
        return 0x17D4;
    }
    k1 = *(s64 *)arg1;
    if (k1 != k0) {
        return 0x17D4;
    }
    u18 = *((u8 *)arg1 + 0x18);
    if (u18 != t18) {
        return 0x17E3;
    }
    if (arg2 == 0) {
        return 0x17D4;
    }
    if (*(s64 *)arg2 != k1) {
        return 0x17D4;
    }
    if (*((u8 *)arg2 + 0x18) != u18) {
        return 0x17E3;
    }
    if (arg3 == 0) {
        return 0x181A;
    }
    if (*(s32 *)((u8 *)arg3 + 0x8) == 0) {
        return 0x17F2;
    }
    if (*(s32 *)arg3 == 0) {
        return 0x17ED;
    }
    w0 = *(u16 *)((u8 *)arg3 + 0xE);
    w1 = *(u16 *)((u8 *)arg3 + 0xC);
    if (!(w0 < w1)) {
        return 0x1801;
    }
    if (!(*(u16 *)((u8 *)arg3 + 0x12) < w1)) {
        return 0x1806;
    }
    if (!(*((u8 *)arg3 + 0x10) < 8)) {
        return 0x17F7;
    }
    if (!(*((u8 *)arg3 + 0x14) < 8)) {
        return 0x17FC;
    }
    if (arg4 == 0) {
        return 0x181A;
    }
    if (*(s32 *)((u8 *)arg4 + 0x8) == 0) {
        return 0x17F2;
    }
    if (*(s32 *)arg4 == 0) {
        return 0x17ED;
    }
    w0 = *(u16 *)((u8 *)arg4 + 0xE);
    w1 = *(u16 *)((u8 *)arg4 + 0xC);
    if (!(w0 < w1)) {
        return 0x1801;
    }
    if (!(*(u16 *)((u8 *)arg4 + 0x12) < w1)) {
        return 0x1806;
    }
    if (!(*((u8 *)arg4 + 0x10) < 8)) {
        return 0x17F7;
    }
    if (!(*((u8 *)arg4 + 0x14) < 8)) {
        return 0x17FC;
    }
    if (arg5 == 0) {
        return 0x181A;
    }
    if (*(s32 *)((u8 *)arg5 + 0x8) == 0) {
        return 0x17F2;
    }
    if (*(s32 *)arg5 == 0) {
        return 0x17ED;
    }
    w0 = *(u16 *)((u8 *)arg5 + 0xE);
    w1 = *(u16 *)((u8 *)arg5 + 0xC);
    if (!(w0 < w1)) {
        return 0x1801;
    }
    if (!(*(u16 *)((u8 *)arg5 + 0x12) < w1)) {
        return 0x1806;
    }
    if (!(*((u8 *)arg5 + 0x10) < 8)) {
        return 0x17F7;
    }
    if (!(*((u8 *)arg5 + 0x14) < 8)) {
        return 0x17FC;
    }

    *(void **)((u8 *)arg0 + 0x28) = arg3;
    *(void **)((u8 *)arg1 + 0x28) = arg4;
    *(void **)((u8 *)arg2 + 0x28) = arg5;
    if (D_0016F750[0] == 3) {
        func_00147AE0(arg2);
        func_00147AE0(arg1);
        func_00147AE0(arg0);
    }
    func_00147638();
    func_00150648(arg0, arg1, arg2, &sp50, &sp54, 0, 0, 0, &sp58, &sp5C, 0, 0, 0, &sp60, &sp64, 0, 0, 0);
    func_0014F450(sp50, sp54, sp58, sp5C, sp60, sp64, 0xA0, *(s32 *)arg3, *(s32 *)((u8 *)arg0 + 0x1C), *(s32 *)((u8 *)arg1 + 0x1C), *(s32 *)((u8 *)arg2 + 0x1C));
    if (D_0016F750[0] == 3) {
        func_00147AF0(arg2);
        func_00147AF0(arg1);
        func_00147AF0(arg0);
    }
    return 0;
}
