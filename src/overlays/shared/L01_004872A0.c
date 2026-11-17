#include "common.h"

typedef struct Type3 {
    char _p0[8];
    f32 f8;
    char _pC[0x24 - 0xC];
} Type3;

typedef struct Type4 {
    char _p0[0x3C];
    u8 *f3C;
} Type4;

extern void func_00591C70(void *object, s32 arg1);
extern s32 func_L00_005E8F08(void *o, s32 a, s32 b);
extern void func_L00_005EB528(void *object, s32 a1, s32 a2, s32 a3);
extern void func_L00_005F15B8(s32 arg0);
extern void func_L00_005F1778(int, void *, int);
extern void func_L00_005F83B0(void *object, f32 *out, void *other);
extern void func_L00_0066CC68(s32, s32);
extern s32 func_L00_0066D220(s32, s32, void *);
extern s32 func_L01_0056CDB0(u8 *object);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A1B38(void *p);
extern s32 func_L01_00627BD8(u32 a0);
extern Type3 D_003BD3C8[];
extern Type4 D_2423C0[];
extern s32 D_0021DF64;

// Applies one frame of contact to the object: reduces the field at 0xF0 by the contact distance times a table value, then resets the contact state.
s32 func_L01_004872A0(u8 *arg0) {
    u8 *p;
    void *other;
    f32 dist;
    s32 var;
    s32 idx;
    u32 tmp;

    p = *(u8 **)(arg0 + 0xAC);
    p[0x282] = 0;
    if (arg0[0x20] == 9 || arg0[0x20] == 7 || arg0[0x20] == 4) {
        return 0;
    }
    *(s16 *)(p + 0x2C4) = 0;
    if (arg0[0x2C] == 0xFF || ((Type4 *)((arg0[0x2C] << 6) + (u32)D_2423C0))->f3C != arg0) {
        other = NULL;
    } else {
        other = (void *)func_L00_005E8F08(arg0, -1, 0);
    }
    dist = 0.0f;
    func_L00_005F83B0(arg0, &dist, other);
    if (dist > 0.0f) {
        if (arg0[0x67] != 0) {
            func_L00_005EB528(arg0, 1, 0, 0);
            *(f32 *)(p + 0xF0) = *(f32 *)(p + 0xF0) - dist * D_003BD3C8[D_0021DF64].f8;
            if (arg0[0x67] == 3 && other != NULL && ((u8 *)other)[0x29] >= 2) {
                func_L00_0066CC68(0xA, (s32)arg0);
                func_L01_0056CDB0(arg0);
                func_00591C70(arg0, 7);
            }
            if (*(f32 *)(p + 0xF0) <= 0.0f) {
                func_L01_00591BD8(arg0, 4, -1);
            } else {
                func_L00_0066D220(8, 0, arg0);
            }
        }
    }
    arg0[0x2C] = 0xFF;
    if (arg0[0x67] != 0) {
        func_L00_005F15B8((s32)arg0);
    }
    func_L01_005A1B38(arg0);
    if (arg0[0x67] == 4) {
        return 0;
    }
    var = *(s32 *)(p + 0x60);
    if (var != 0 || ((idx = *(s32 *)(p + 0x74)) >= 0 && (var = *(s32 *)(p + (idx << 2) + 0xA0)) != 0)) {
        func_L00_005F1778(var, p + 0x2F0, 0);
        *(s16 *)(p + 0x2C4) = 1;
    }
    tmp = *(u32 *)(p + 0x2A0);
    if (tmp == 0xFFFFFFFF) {
        return 0;
    }
    func_L01_00627BD8(tmp);
    *(u32 *)(p + 0x2A0) = 0xFFFFFFFF;
    return 0;
}
