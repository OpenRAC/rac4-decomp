#include "common.h"

extern s32 D_00221790;
extern s32 D_003092A0[];
extern s32 func_00506BB8(void);
extern void func_005026A8(s32 *, s32, s32);
extern s32 func_00506C08(s32, s32);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(u32, const char *);
extern s32 func_005064A8(s32, f32);
extern s32 func_005063C0(s32, s32);
extern s32 func_00506978(s32, f32, f32);
extern void func_00498618(s32, s32, s32);
extern s32 func_00506590(s32, s32);
extern s32 func_005060D8(s32, s32);

void func_004AECE8(void) {
    s32 index = func_00506BB8();
    s32 record = index * 0x50 + (s32)D_003092A0;
    s32 first = record + 8;
    s32 second = record + 0x18;

    func_005026A8(&D_00221790, 6, -1);
    func_00506C08(5, D_00221790);
    func_005062D0(func_004A2798(&D_00221790, 5), (const char *)(record + 0x48));
    func_005064A8(func_004A2798(&D_00221790, 5), *(f32 *)(record + 0x40));
    func_005063C0(func_004A2798(&D_00221790, 5), 0x8020F0F0);
    func_00506978(func_004A2798(&D_00221790, 5), 0.9f, 1.199997f);
    func_005062D0(func_004A2798(&D_00221790, 3), (const char *)first);
    func_00498618(first, *(s32 *)(record + 0x2C), 0);
    func_005062D0(func_004A2798(&D_00221790, 4), (const char *)second);
    func_005064A8(func_004A2798(&D_00221790, 4), (f32)*(s32 *)(record + 0x34) / 5.0f);
    func_00498618(second, *(s32 *)(record + 0x30), 1);
    func_00506590(func_004A2798(&D_00221790, 2), 0x7534);
    func_005060D8(func_004A2798(&D_00221790, 2), 1);
}
