#include "common.h"

extern s32 D_0031D100[];
extern s32 D_00221BD8;
extern u8 D_001CDB70[];
extern s32 func_00506BB8(void);
extern void func_005026A8(s32, s32, s32);
extern void func_00506C08(s32, s32);
extern s32 func_004A2798(const s32 *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(u32, const char *);
extern s32 func_0049A9D8(s32, s32);
extern void func_00506590(s32, s32);
extern void func_005071B8(s32, s32);

void func_004D7290(void) {
    s32 *record = (s32 *)(func_00506BB8() * 0x528 + (s32)D_0031D100);
    func_005026A8((s32)&D_00221BD8, 0x29, -1);
    func_00506C08(0xF, D_00221BD8);
    func_005062D0(func_004A2798(&D_00221BD8, 0xA), func_0045E850(0x2350));
    func_005062D0(func_004A2798(&D_00221BD8, 9), func_0045E850(0x31CE));
    func_005062D0(func_004A2798(&D_00221BD8, 0xB), func_0045E850(0x2F0B));
    record[2] = func_0049A9D8((s32)D_001CDB70, -1);
    func_00506590(func_004A2798(&D_00221BD8, 4), 1);
    func_005071B8(func_004A2798(&D_00221BD8, 4), record[2]);
}
