#include "common.h"

extern s32 D_002218D8;
extern s8 D_0030D158[];
extern s8 D_0021FA20[];
extern s8 D_0030E500[];
extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, const char *);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B70(s32 index, s32 handle);
extern void func_005061D8(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00506408(u32 id, s32 a, s32 b, f32 value);

void func_004C9340(void)
{
    s32 other;
    s32 resource;
    s32 text;
    s32 label;
    s8 *format;
    s8 *buffer;

    func_00501638(&D_002218D8, 0x2B, -1);
    func_00505B70(0xF, D_002218D8);
    resource = func_004A1A60(&D_002218D8, 0x15);
    text = func_0045E038(0x2F2A);
    func_00505238(resource, (const char *)text);
    other = func_004A1A60(&D_002218D8, 0x13);
    func_00505238(other, (const char *)D_0030E500);
    buffer = D_0030D158;
    format = D_0021FA20;
    label = func_0045E038(0x234F);
    func_0011D920(buffer, format, label, func_0045E038(0x2350));
    other = func_004A1A60(&D_002218D8, 0x14);
    func_00505238(other, (const char *)buffer);
    other = func_004A1A60(&D_002218D8, 0x11);
    func_005054F8(other, 0x7534);
    other = func_004A1A60(&D_002218D8, 0x17);
    func_005061D8(other, 1, 1, 1, 0, 0, 0, 0, 0);
    other = func_004A1A60(&D_002218D8, 0x17);
    func_00505040(other, 1);
    other = func_004A1A60(&D_002218D8, 0x17);
    func_00506408(other, 0xB4, 0xA, 0.00031f);
}
