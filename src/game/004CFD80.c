#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_00497848(s32 i);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern void func_00501730(s32 *group, s32 owner, f32 value);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);
extern void func_005061D8(s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern s32 func_00506408(u32 id, s32 a, s32 b, f32 value);
extern s32 D_00221980;

void func_004CFD80(void) {
    s32 index = func_00505B20();
    func_00501638(&D_00221980, 0x23, -1);
    func_00505B70(0xF, D_00221980);
    func_00501730(&D_00221980, -1, (f32)func_00497848(index));
    func_00505238(func_004A1A60(&D_00221980, 0xB), (const char *)func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_00221980, 0xC), (const char *)func_0045E038(0x237D));
    func_005061D8(func_004A1A60(&D_00221980, 0xD), 1, 1, 1, 0, 0, 0, 0, 0);
    func_00505040(func_004A1A60(&D_00221980, 0xD), 1);
    func_00506408(func_004A1A60(&D_00221980, 0xD), 0xB4, 0xA, 0.00031f);
}
