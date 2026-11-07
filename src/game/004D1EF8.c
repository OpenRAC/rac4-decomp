#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_00497848(u32 i);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern void func_00501730(s32 *group, s32 arg1, f32 value);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);
extern void func_005061D8(s32 id, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8);
extern s32 func_00506408(u32 id, s32 a, s32 b, f32 value);

extern s32 D_002219C0;

void func_004D1EF8(void)
{
    s32 index = func_00505B20();
    s32 id;

    func_00501638(&D_002219C0, 0x33, -1);
    func_00505B70(0xF, D_002219C0);
    func_00501730(&D_002219C0, -1, (f32)func_00497848(index));
    id = func_004A1A60(&D_002219C0, 0xE);
    func_00505238(id, (const char *)func_0045E038(0x2350));
    id = func_004A1A60(&D_002219C0, 0xF);
    func_00505238(id, (const char *)func_0045E038(0x2387));
    func_005061D8(func_004A1A60(&D_002219C0, 0x10), 1, 1, 1, 0, 0, 0, 0, 0);
    func_00505040(func_004A1A60(&D_002219C0, 0x10), 1);
    func_00506408(func_004A1A60(&D_002219C0, 0x10), 0xB4, 0xA, 0.00031f);
}
