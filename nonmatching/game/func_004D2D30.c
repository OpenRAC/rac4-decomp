/* Not matching yet: BYTES 40/712 (tools/try_func.py func_004D2D30 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    void (*fC)(u32);
    s32 f10;
    s32 f14;
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    void (*f10)(u32);
    s32 f14;
    s32 f18;
} Entry;

extern const char *func_0045E038(s32);
extern s32 func_00497848(u32 i);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern void func_00501730(s32 *group, s32 a, f32 value);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(s32, const char *);
extern s32 func_00505B20(void);
extern s32 func_00505B70(s32 index, s32 handle);
extern void func_005061D8(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00506408(u32 id, s32 a, s32 b, f32 value);
extern Type2 D_003D2A00[];
extern s32 D_003D2A78[][5];
extern s32 D_002219E0;
extern Entry D_0031B6B0[];

void func_004D2D30(void) {
    s32 i;
    s32 j;
    s32 idx = func_00505B20();
    Entry *e = &D_0031B6B0[idx];
    Type2 *tbl;

    func_00501638(&D_002219E0, 0x38, -1);
    func_00505B70(0x11, D_002219E0);
    func_00501730(&D_002219E0, -1, (f32)func_00497848(idx));
    func_00505238(func_004A1A60(&D_002219E0, 6), 0);
    func_00505238(func_004A1A60(&D_002219E0, 7), func_0045E038(0x177));
    func_00505238(func_004A1A60(&D_002219E0, 8), func_0045E038(0x3782));
    tbl = D_003D2A00;
    for (i = 0; i < 5; i++) {
        s32 *row = D_003D2A78[i];
        func_00505238(func_004A1A60(&D_002219E0, *(s32 *)((u8 *)tbl + 4 + i * 0x18)), func_0045E038(*(s32 *)((u8 *)D_003D2A00 + 0x14 + i * 0x18)));
        for (j = 0; j < 5; j++) {
            func_00505040(func_004A1A60(&D_002219E0, *row++), 1);
        }
        if (i == 4) {
            if (e->fC != 0) {
                func_00505238(func_004A1A60(&D_002219E0, tbl[4].f4), func_0045E038(tbl[4].f14));
            } else {
                func_00505238(func_004A1A60(&D_002219E0, tbl[4].f4), func_0045E038(0x16F));
            }
        }
    }
    func_005061D8(func_004A1A60(&D_002219E0, 5), 1, 1, 1, 0, 0, 0, 0, 0);
    func_00505040(func_004A1A60(&D_002219E0, 5), 1);
    func_00506408(func_004A1A60(&D_002219E0, 5), 0xB4, 0xA, 0.00031f);
}
