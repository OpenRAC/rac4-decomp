#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Entry;

extern void func_0049C158(s32 param_a, s32 param_b, s32 source, s32 mode);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505328(s32 handle, u32 value);
extern s32 func_00505B20(void);
extern Entry D_003D2A00[];
extern s32 D_003D2A78[5][5];
extern s32 D_2219E0;

// Sets 0x80D0D0D0 on entry arg0's handle, 0x8020F0F0 on each of its row's handles, then calls func_0049C158.
void func_004D2988(s32 arg0) {
    s32 i;
    s32 *p;

    func_00505328(func_004A1A60(&D_2219E0, D_003D2A00[arg0].f4), 0x80D0D0D0);
    p = D_003D2A78[arg0];
    for (i = 4; i >= 0; i--) {
        func_00505328(func_004A1A60(&D_2219E0, *p++), 0x8020F0F0);
    }
    func_0049C158(func_00505B20(), 3, func_004A1A60(&D_2219E0, D_003D2A00[arg0].f0), 0);
}
