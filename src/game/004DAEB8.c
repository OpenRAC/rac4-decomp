#include "common.h"

extern s32 func_0011D920(char *buf, const char *fmt, ...);
extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00504F68(u32, s32);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, const char *);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B70(s32 index, s32 handle);
extern void func_005061D8(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00506408(u32 id, s32 a, s32 b, f32 value);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern char D_0021FC70[];
extern char D_0021FC80[];
extern s32 D_00221B78;
extern char D_00321B18[];
extern char D_00322F10[];

void func_004DAEB8(void) {
    s32 id;

    func_00501638(&D_00221B78, 0x2D, -1);
    func_00505B70(0xF, D_00221B78);
    id = func_004A1A60(&D_00221B78, 0x15);
    func_00505238(id, (const char *)func_0045E038(0x139E));
    func_00505238(func_004A1A60(&D_00221B78, 0x13), D_00322F10);
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        char *fmt = D_0021FC70;
        s32 a = func_0045E038(0x3468);
        s32 b = func_0045E038(0x234F);
        func_0011D920(D_00321B18, fmt, a, b, func_0045E038(0x2350));
    } else {
        char *fmt = D_0021FC80;
        s32 b = func_0045E038(0x234F);
        func_0011D920(D_00321B18, fmt, b, func_0045E038(0x2350));
    }
    func_00505238(func_004A1A60(&D_00221B78, 0x14), D_00321B18);
    func_005054F8(func_004A1A60(&D_00221B78, 0x11), 0x7546);
    func_005061D8(func_004A1A60(&D_00221B78, 0x17), 1, 1, 1, 0, 0, 0, 0, 0);
    func_00505040(func_004A1A60(&D_00221B78, 0x17), 1);
    func_00506408(func_004A1A60(&D_00221B78, 0x17), 0xB4, 0xA, 0.00031f);
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        id = func_004A1A60(&D_00221B78, 0x18);
        func_00505238(id, (const char *)func_0045E038(0x301A));
        func_00504F68(func_004A1A60(&D_00221B78, 0x18), 1);
    }
}
