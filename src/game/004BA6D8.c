#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type1;

extern void func_0049C158(s32 param_a, s32 param_b, s32 source, s32 mode);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505328(s32 handle, u32 value);
extern s32 func_00505B20(void);
extern s32 D_2217E0;
extern Type1 D_003D9528[];
extern Type1 D_30A490[];

void func_004BA6D8(void) {
    s32 index = func_00505B20();
    s32 i = D_30A490[index].f4;

    func_0049C158(index, 0, func_004A1A60(&D_2217E0, D_003D9528[i].f4), 0);
    func_00505328(func_004A1A60(&D_2217E0, D_003D9528[i].f8), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_2217E0, D_003D9528[i].fC), 0x80D0D0D0);
}
