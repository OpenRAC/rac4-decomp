#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern s32 func_00497848(u32 i);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern void func_00501730(s32 *group, s32 a, f32 value);
extern s32 func_00505238(s32 handle, u32 value);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);
extern u8 D_0021FAA8[];
extern s32 D_221940;
extern u8 D_30EC90[];

// Sets up the group at D_221940 for the current index, then registers the two resource handles.
void func_004CE2F8(void)
{
    u8 *grp;
    u8 *aux;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_s0_2;

    temp_s0 = func_00505B20();
    func_00501638(&D_221940, 0x1D, -1);
    func_00505B70(0xF, D_221940);
    func_00501730(&D_221940, -1, (f32) func_00497848(temp_s0));
    grp = D_30EC90;
    aux = D_0021FAA8;
    temp_s2 = func_0045E038(0x234F);
    func_0011D920((s8 *) grp, (s8 *) aux, temp_s2, func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_221940, 0xB), (u32) grp);
    temp_s0_2 = func_004A1A60(&D_221940, 0xC);
    func_00505238(temp_s0_2, func_0045E038(0x235F));
}
