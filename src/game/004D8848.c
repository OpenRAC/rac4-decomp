#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505238(u32, const char *);
extern void func_005054F8(s32, u16);
extern s32 func_00505B70(s32 index, s32 handle);

extern s32 D_00221B28;
extern s8 D_00320148[];
extern s8 D_0021FC30[];

void func_004D8848(void) {
    s32 temp_s0;
    s32 temp_s2;
    s8 *buf;
    s8 *fmt;

    func_00501638(&D_00221B28, 0x37, -1);
    func_00505B70(0xF, D_00221B28);
    temp_s0 = func_004A1A60(&D_00221B28, 3);
    func_00505238(temp_s0, (const char *)func_0045E038(0x31D4));
    buf = D_00320148;
    fmt = D_0021FC30;
    temp_s2 = func_0045E038(0x3265);
    func_0011D920(buf, fmt, temp_s2, func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_00221B28, 2), (const char *)buf);
    func_005054F8(func_004A1A60(&D_00221B28, 4), 1);
}
