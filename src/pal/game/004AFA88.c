#include "common.h"

extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_003093A0[];
extern s32 D_003D1AE8[];
extern s32 D_003D9318[];
extern s32 D_003D8560[];
extern s32 D_002217B0;
extern s32 func_00506BB8(void);
extern s32 func_004AF6B0(s32);
extern s32 func_004A2798(const s32 *, s32);
extern void func_00506000(s32, s32);
extern void func_00506590(s32, u32);

static inline u32 address(u32 base, u32 offset)
{
    return base + offset;
}

void func_004AFA88(void)
{
    s32 index = func_00506BB8();
    s32 *record;
    s32 *entries;
    s32 *values;
    s32 *params;
    s32 i;
    record = (s32 *)((u32)D_003093A0 + (u32)index * 0x64);
    if (D_0021EE54 != 0 || D_0021EE58 != 0) {
        return;
    }
    entries = (s32 *)address((u32)D_003D1AE8, 8);
    values = D_003D9318;
    params = record + 0xA;
    for (i = 0; i < 4; i++) {
        if (func_004AF6B0(i) != 0) {
            func_00506000(func_004A2798(&D_002217B0, entries[0]), params[0] != 0);
        } else {
            s32 value = values[0];
            u32 *resource = (u32 *)((u32)D_003D8560 + ((u32)value << 5));
            s32 handle = func_004A2798(&D_002217B0, entries[0]);
            func_00506590(handle, *resource);
            func_00506000(func_004A2798(&D_002217B0, entries[0]), 1);
        }
        entries += 3;
        values += 3;
        params++;
    }
}
