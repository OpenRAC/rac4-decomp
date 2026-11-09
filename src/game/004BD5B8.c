#include "common.h"
extern void func_0049C290(s32, s32);
extern void func_0049C400(s32, s32, s32, s32, s32);
extern void func_0049D170(s32, s32, s32);
extern void func_0049D280(s32, s32);
extern void func_004A0BE8(void *, s32);
extern void func_004A0BF0(void *, s32, s32);
extern void func_004A1140(void *, void *, s32, void *, s32, s32);
extern s32 func_004A1A60(s32 *, s32);
extern void func_004BE3A0(void);
extern s32 func_00505B20(void);
extern void func_00505DD0(s32, s32);
extern void func_004C10F0(void);
extern s32 D_221860;
extern u8 D_30B358[];
void func_004BD5B8(void) {
    s32 value;
    s32 owner = func_00505B20();
    u8 *root = owner * 0x258 + D_30B358;
    u8 *entry;
    *(f32 *)(root + 0x10) = 0.9f;
    entry = root + 0x1EC;
    func_004BE3A0();
    func_004A1140(entry, root + 0x24, 0x13, func_004C10F0, 0x32, 1);
    func_00505DD0(D_221860, *(s32 *)(entry + 0x2C));
    func_004A0BF0(entry, func_004A1A60(&D_221860, 8), 1);
    func_004A0BE8(entry, 1);
    func_0049D170(owner, 0, func_004A1A60(&D_221860, 0xC));
    func_0049D280(owner, 1);
    value = D_221860;
    func_0049C400(owner, 0, value, func_004A1A60(&D_221860, 0xC), 0);
    func_0049C290(owner, 1);
    *(s32 *)(root + 0xC) = 0;
    *(s32 *)(root + 4) = 7;
    *(u8 *)(root + 8) = 0;
    *(s32 *)root = 0;
}
