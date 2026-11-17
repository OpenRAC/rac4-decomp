#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00504648(s32 handle, float *a, float *b);
extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505238(s32 handle, u32 value);
extern s32 func_00505328(s32 handle, u32 value);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_005058E0(u32 id, f32 a, f32 b);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);
extern s32 func_00506120(u32 id, u32 value);
extern s32 D_0021F198;
extern s8 D_0021F950[];
extern s8 D_0021F958[];
extern u8 D_1CDAC0[];
extern s32 D_221860;
extern s8 D_30B088[];
extern u8 D_30B358[];

/* Fills the record at D_30B358 + slot * 0x258 with ids and scaled float values from the 0x221860 table. */
void func_004BE3A0(void) {
    f32 sp0;
    f32 sp4;
    u8 *temp_s4;
    s32 temp_s0;
    f32 temp_f20;

    temp_s4 = D_30B358 + (func_00505B20() * 0x258);
    func_00501638(&D_221860, 0x31, -1);
    func_00505B70(0xF, D_221860);
    func_00505238(func_004A1A60(&D_221860, 0x11), (u32)D_30B088);
    if (D_0021F198 == -1) {
        s8 *fmt1 = D_0021F950;
        s32 a1 = func_0045E038(0x2EE9);
        func_0011D920(D_30B088, fmt1, a1, func_0045E038(0x234F));
    } else {
        s8 *fmt2 = D_0021F958;
        s32 b1 = func_0045E038(0x2EE9);
        s32 b2 = func_0045E038(0x234F);
        s32 b3 = func_0045E038(0x2350);
        func_0011D920(D_30B088, fmt2, b1, b2, b3);
    }
    func_00505328(func_004A1A60(&D_221860, 0x11), 0x80808080);
    temp_s0 = func_004A1A60(&D_221860, 0x12);
    func_00505238(temp_s0, func_0045E038(0x2EF1));
    temp_s0 = func_004A1A60(&D_221860, 0x10);
    func_00505238(temp_s0, func_0045E038(0x111));
    func_00505328(func_004A1A60(&D_221860, 0x10), 0x80808080);
    func_005054F8(func_004A1A60(&D_221860, 9), 1);
    func_005054F8(func_004A1A60(&D_221860, 0xB), 1);
    func_005054F8(func_004A1A60(&D_221860, 0x1A), 0x754B);
    func_00505328(func_004A1A60(&D_221860, 0x1A), 0x80808080);
    temp_s0 = func_004A1A60(&D_221860, 0x1B);
    func_00505238(temp_s0, func_0045E038(0x2EEB));
    temp_f20 = *(f32 *)(temp_s4 + 0x10);
    sp0 = 0.0f;
    sp4 = 0.0f;
    temp_s0 = func_004A1A60(&D_221860, 0x1C);
    func_00505238(temp_s0, func_0045E038(0x2EEC));
    temp_s0 = func_004A1A60(&D_221860, 0x20);
    func_00505238(temp_s0, func_0045E038(0x2EED));
    func_00504648(func_004A1A60(&D_221860, 0x1C), &sp0, &sp4);
    func_005058E0(func_004A1A60(&D_221860, 0x1C), temp_f20 * sp0, temp_f20 * sp4);
    func_00504648(func_004A1A60(&D_221860, 0x1D), &sp0, &sp4);
    func_005058E0(func_004A1A60(&D_221860, 0x1D), temp_f20 * sp0, temp_f20 * sp4);
    func_00504648(func_004A1A60(&D_221860, 0x20), &sp0, &sp4);
    func_005058E0(func_004A1A60(&D_221860, 0x20), temp_f20 * sp0, temp_f20 * sp4);
    func_00504648(func_004A1A60(&D_221860, 0x21), &sp0, &sp4);
    func_005058E0(func_004A1A60(&D_221860, 0x21), temp_f20 * sp0, temp_f20 * sp4);
    temp_s0 = func_004A1A60(&D_221860, 0x28);
    func_00505238(temp_s0, func_0045E038(0x2EF8));
    func_00504F68(func_004A1A60(&D_221860, 0x28), 0);
    *(s32 *)(temp_s4 + 0x1C) = func_00499CA0(D_1CDAC0, -1);
    func_005054F8(func_004A1A60(&D_221860, 7), 1);
    func_00506120(func_004A1A60(&D_221860, 7), *(s32 *)(temp_s4 + 0x1C));
    *(s32 *)(temp_s4 + 0x20) = func_00499CA0(D_1CDAC0 - 8, -1);
    func_005054F8(func_004A1A60(&D_221860, 6), 1);
    func_00506120(func_004A1A60(&D_221860, 6), *(s32 *)(temp_s4 + 0x20));
    func_00504F68(func_004A1A60(&D_221860, 0x17), 0);
}
