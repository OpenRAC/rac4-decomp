/* Not matching yet: BYTES 17/236 (tools/try_func.py func_004A8E78 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    u8 pad00[0x70];
    s32 unk70;
    s32 unk74;
    s32 unk78;
    u8 pad7C[0x3C];
} Entry;

extern s32 func_004A86E0(void);
extern void func_004A8778(s32 arg0, s32 arg1);
extern void func_004A89A0(s32 arg0, s32 arg1);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 func_00547E00(s32, s32);
extern s32 func_00547E30(s32 arg0, s32 arg1);
extern s32 func_00548018(s32 arg0);
extern u8 *D_0021DFF0[];
extern s32 D_0021EDD4[];
extern Entry D_00308108[];

void func_004A8E78(void) {
    s32 idx = func_00505B20();
    s32 b = func_004A86E0();
    Entry *e = &D_00308108[idx];
    u8 *obj = func_00510BE8(idx);
    s32 v;
    s32 w;

    if (func_00548018(b) != 0) {
        v = 0;
    } else {
        v = func_00547E30(*(s32 *)(obj + 0x26E4), b);
    }
    if (D_0021EDD4[0] == 1) {
        if (*(s8 *)(D_0021DFF0[0] + 0x20) != 0) {
            v = 0;
        }
    }
    if (e->unk70 != v) {
        e->unk70 = v;
        func_004A8778(idx, v);
    }
    w = func_00547E00(*(s32 *)(obj + 0x26E4), b);
    e->unk74 = w;
    if (e->unk78 != w) {
        e->unk78 = w;
        func_004A89A0(idx, w);
    }
}
