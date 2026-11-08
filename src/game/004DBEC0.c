#include "common.h"

typedef struct Entry {
    u8 pad[0x150];
    s32 f150;
    s32 f154;
    u8 tail[0x10];
} Entry;

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern char *func_0045E038(s32);
extern s32 func_00497848(u32 i);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern void func_00501730(s32 *group, s32 a, f32 value);
extern s32 func_00505238(u32, const char *);
extern void func_00505328(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);
extern s32 func_00506120(u32 id, u32 value);

extern s8 D_0021FC88[];
extern s32 D_001CDAB8[];
extern s32 D_00221B88;
extern s8 D_00322F98[];
extern Entry D_00322FC8[];

void func_004DBEC0(void) {
    s32 idx;
    Entry *e;
    char *a;
    s32 h;
    s8 *dst;
    s8 *fmt;

    idx = func_00505B20();
    e = &D_00322FC8[idx];
    func_00501638(&D_00221B88, 0x39, -1);
    func_00505B70(0xF, D_00221B88);
    func_00501730(&D_00221B88, -1, (f32)func_00497848(idx));
    dst = D_00322F98;
    fmt = D_0021FC88;
    a = func_0045E038(0x3265);
    func_0011D920(dst, fmt, a, func_0045E038(0x2350));
    h = func_004A1A60(&D_00221B88, 6);
    func_00505238(h, func_0045E038(0x2350));
    func_00505328(func_004A1A60(&D_00221B88, 6), 0x80808080);
    h = func_004A1A60(&D_00221B88, 5);
    func_00505238(h, func_0045E038(0x3273));
    func_00505328(func_004A1A60(&D_00221B88, 5), 0x80808080);
    h = func_004A1A60(&D_00221B88, 0xB);
    func_00505238(h, func_0045E038(0x3240));
    h = func_004A1A60(&D_00221B88, 0xF);
    func_00505238(h, func_0045E038(0x3241));
    h = func_004A1A60(&D_00221B88, 0xD);
    func_00505238(h, func_0045E038(0x3242));
    h = func_004A1A60(&D_00221B88, 0xE);
    func_00505238(h, func_0045E038(0x3243));
    e->f154 = func_00499CA0(D_001CDAB8, -1);
    func_005054F8(func_004A1A60(&D_00221B88, 3), 1);
    func_00506120(func_004A1A60(&D_00221B88, 3), e->f154);
    e->f150 = func_00499CA0(D_001CDAB8 + 2, -1);
    func_005054F8(func_004A1A60(&D_00221B88, 1), 1);
    func_00506120(func_004A1A60(&D_00221B88, 1), e->f150);
    func_005054F8(func_004A1A60(&D_00221B88, 4), 1);
}
