#include "common.h"

extern s32 D_00221AF8;
extern char D_0031B988[];
extern const char D_0021FC68[];
extern const char D_0031CD30[];
extern void func_005026A8(s32 *, s32, s32);
extern void func_00506C08(s32, s32);
extern s32 func_004A2798(s32 *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(u32, const char *);
extern s32 func_0011D920(char *, const char *, ...);
extern void func_00506590(s32, s32);
extern s32 func_00507270(u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_005060D8(s32, s32);
extern void func_005074A0(s32, f32, s32, s32);

void func_004D6920(void)
{
    s32 other;
    s32 resource;
    const char *text;
    const char *label;
    const char *format;
    char *buffer;

    func_005026A8(&D_00221AF8, 0x2D, -1);
    func_00506C08(0xF, D_00221AF8);
    resource = func_004A2798(&D_00221AF8, 0x15);
    text = func_0045E850(0x2F2A);
    func_005062D0(resource, text);
    other = func_004A2798(&D_00221AF8, 0x13);
    func_005062D0(other, D_0031CD30);
    buffer = D_0031B988;
    format = D_0021FC68;
    label = func_0045E850(0x234F);
    func_0011D920(buffer, format, label, func_0045E850(0x2350));
    other = func_004A2798(&D_00221AF8, 0x14);
    func_005062D0(other, buffer);
    other = func_004A2798(&D_00221AF8, 0x11);
    func_00506590(other, 0x7534);
    other = func_004A2798(&D_00221AF8, 0x17);
    func_00507270(other, 1, 1, 1, 0, 0, 0, 0, 0);
    other = func_004A2798(&D_00221AF8, 0x17);
    func_005060D8(other, 1);
    other = func_004A2798(&D_00221AF8, 0x17);
    func_005074A0(other, 0.00031f, 0xB4, 0xA);
}
