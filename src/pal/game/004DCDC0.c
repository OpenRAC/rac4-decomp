#include "common.h"

extern s32 D_00221C88;
extern char D_00322FC8[];
extern char D_00322F98[];
extern const char D_0021FD30[];
extern char D_001CDB38[];
extern char D_001CDB40[];

extern s32 func_00506BB8(void);
extern void func_005026A8(s32 *, s32, s32);
extern void func_00506C08(s32, s32);
extern s32 func_004984A0(s32);
extern void func_005027A0(s32 *, s32, f32);
extern const char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_004A2798(const s32 *, s32);
extern s32 func_005062D0(u32, const char *);
extern void func_005063C0(s32, u32);
extern s32 func_00507270(u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_005074A0(s32, f32, s32, s32);
extern s32 func_0049A9D8(void *, s32);
extern void func_00506590(s32, s32);
extern void func_005071B8(s32, s32);

void func_004DCDC0(void)
{
    s32 index = func_00506BB8();
    s32 *record = (s32 *)(index * 0x168 + (s32)D_00322FC8);
    s32 other;
    const char *label;
    char *buffer;
    const char *format;
    char *resource;

    func_005026A8(&D_00221C88, 0x39, -1);
    func_00506C08(0xF, D_00221C88);
    func_005027A0(&D_00221C88, -1, (f32)func_004984A0(index));

    buffer = D_00322F98;
    format = D_0021FD30;
    label = func_0045E850(0x3265);
    func_0011D920(buffer, format, label, func_0045E850(0x2350));
    other = func_004A2798(&D_00221C88, 6);
    func_005062D0(other, func_0045E850(0x2350));
    other = func_004A2798(&D_00221C88, 6);
    func_005063C0(other, 0x80808080);
    other = func_004A2798(&D_00221C88, 5);
    func_005062D0(other, func_0045E850(0x3273));
    other = func_004A2798(&D_00221C88, 5);
    func_005063C0(other, 0x80808080);
    other = func_004A2798(&D_00221C88, 0x11);
    func_00507270(other, 1, 1, 1, 0, 0, 0, 0, 0);
    other = func_004A2798(&D_00221C88, 0x11);
    func_005074A0(other, 0.0005f, 0x5A, 0xA);
    other = func_004A2798(&D_00221C88, 0xB);
    func_005062D0(other, func_0045E850(0x3240));
    other = func_004A2798(&D_00221C88, 0xF);
    func_005062D0(other, func_0045E850(0x3241));
    other = func_004A2798(&D_00221C88, 0xD);
    func_005062D0(other, func_0045E850(0x3242));
    other = func_004A2798(&D_00221C88, 0xE);
    func_005062D0(other, func_0045E850(0x3243));

    resource = D_001CDB38;
    record[0x55] = func_0049A9D8(resource, -1);
    other = func_004A2798(&D_00221C88, 3);
    func_00506590(other, 1);
    other = func_004A2798(&D_00221C88, 3);
    func_005071B8(other, record[0x55]);
    record[0x54] = func_0049A9D8(resource + 8, -1);
    other = func_004A2798(&D_00221C88, 1);
    func_00506590(other, 1);
    other = func_004A2798(&D_00221C88, 1);
    func_005071B8(other, record[0x54]);
    other = func_004A2798(&D_00221C88, 4);
    func_00506590(other, 1);
}
