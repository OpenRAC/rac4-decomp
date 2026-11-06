#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505238(u32, const char *);
extern void func_005054F8(s32, u16);
extern s32 func_00505B70(s32 index, s32 handle);

extern s32 D_00221B68;
extern s8 D_00321620[];
extern s8 D_0021FC60[];

void func_004D9BF0(void) {
    s32 t;
    s32 s;
    s8 *buf;
    s8 *format;

    func_00501638(&D_00221B68, 0x37, -1);
    func_00505B70(0xF, D_00221B68);
    t = func_004A1A60(&D_00221B68, 3);
    func_00505238(t, (const char *)func_0045E038(0x31D5));
    buf = D_00321620;
    format = D_0021FC60;
    s = func_0045E038(0x3265);
    func_0011D920(buf, format, s, func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_00221B68, 2), buf);
    func_005054F8(func_004A1A60(&D_00221B68, 4), 1);
}
