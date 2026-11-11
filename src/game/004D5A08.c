#include "common.h"

extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, const char *);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B70(s32 index, s32 handle);
extern void func_005061D8(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00506408(u32 id, s32 a, s32 b, f32 value);
extern s32 D_002219F8;
extern char D_0021FBC0[];
extern char D_0031B988[];
extern char D_0031CD30[];

void func_004D5A08(void) {
    s32 id;
    s32 a;
    char *buf;
    char *fmt;

    func_00501638(&D_002219F8, 0x2D, -1);
    func_00505B70(0xF, D_002219F8);
    id = func_004A1A60(&D_002219F8, 0x15);
    func_00505238(id, (const char *)func_0045E038(0x2F2A));
    func_00505238(func_004A1A60(&D_002219F8, 0x13), D_0031CD30);
    buf = D_0031B988;
    fmt = D_0021FBC0;
    a = func_0045E038(0x234F);
    func_0011D920(buf, fmt, a, func_0045E038(0x2350));
    func_00505238(func_004A1A60(&D_002219F8, 0x14), buf);
    func_005054F8(func_004A1A60(&D_002219F8, 0x11), 0x7534);
    func_005061D8(func_004A1A60(&D_002219F8, 0x17), 1, 1, 1, 0, 0, 0, 0, 0);
    func_00505040(func_004A1A60(&D_002219F8, 0x17), 1);
    func_00506408(func_004A1A60(&D_002219F8, 0x17), 0xB4, 0xA, 0.00031f);
}
