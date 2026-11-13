#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/profile_001721E0.h"

extern s32 func_L00_00774F28(u8 *);
extern void func_L00_00782030(s32);
extern s32 func_L00_00773688(u8 *, s32, char *, s32);
extern s32 func_0015A1A0(u8 *);
extern s32 func_0015AA88(void);
extern s32 func_00161330(void);
extern void func_L00_00774290(u8 *);
extern void func_00161128(s32);
extern s32 func_L00_00773848(u8 *, s32, s32);
extern s32 func_L00_00773A50(u8 *);
extern s32 func_L00_00774780(u8 *);
extern char *func_0011A9EC(void *, void *);
extern void func_00161AA8(s32);
extern void func_00162768(s32);

// Add PAL C for func_L00_00773AF8
s32 func_L00_00773AF8(u8 *st, s32 id, char *str, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 *g;
    s32 ok;

    if (func_L00_00774F28(st) == 0) {
        return 0;
    }
    g = (u8 *)&D_001721E0;
    func_L00_00782030(*(s32 *)((u8 *)D_002234A4 + 0x68));
    st[3] = 0;
    st[0x11] = 0;
    *(s32 *)(g + 0x124) = id;
    ok = func_L00_00773688(st, id, str, arg4);
    if (ok != 0 && func_0015A1A0(st + 0x48) != 0) {
        ok = 0;
    }
    if (ok != 0) {
        *(s32 *)(g + 0x2C) = arg3;
        if (func_0015AA88() != 0) {
            ok = 0;
        }
    }
    if (func_00161330() != 0) {
        if (ok == 0) {
            func_L00_00774290(st);
        }
        return ok;
    }
    if (ok != 0) {
        func_00161128(id);
        ok = func_L00_00773848(st, arg5, arg6);
        if (ok != 0) {
            ok = func_L00_00773A50(st);
            if (ok != 0 && st[0x12] == 0) {
                ok = func_L00_00774780(st);
            }
        }
    }
    if (str != 0) {
        func_0011A9EC(&D_001721E0.region20.bytes[0x1BC], str);
    } else {
        D_001721E0.region20.bytes[0x1BC] = 0;
    }
    if (ok == 0) {
        func_L00_00774290(st);
    } else {
        func_00161AA8(6);
        func_00162768(1);
    }
    return ok;
}
