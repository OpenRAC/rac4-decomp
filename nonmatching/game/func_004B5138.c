/* Not matching yet: BYTES 6/276 (tools/try_func.py func_004B5138 --diff). Not part of the build. */
/* cflags: -ffast-math */
#include "common.h"
typedef struct {
    int f0, f4;
    float current, target;
    char pad10[4];
    int f14;
    char pad18[0x10];
    int f28;
    char pad2C[8];
    int f34;
} State;
extern State D_00309840[];
extern s32 D_00221758;
extern s32 func_00453C68(s32, s32, f32);
extern f32 func_00475710(f32 a, f32 b, f32 c);
extern void func_00497AE0(s32, s32, s32, f32, f32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00505328(s32, s32);
void func_004B5138(void)
{
    s32 c;
    c = func_00453C68(D_00309840[0].f14, 0x80FFFFFF, func_00475710((f32)D_00309840[0].f28, 15.0f, 30.0f));
    func_00505328(func_004A1A60(&D_00221758, 4), c);
    func_00497AE0(func_004A1A60(&D_00221758, 3), func_004A1A60(&D_00221758, 5), D_00309840[0].f34,
                  D_00309840[0].target < D_00309840[0].current ? D_00309840[0].target : D_00309840[0].current, 0.0f);
    func_00497AE0(func_004A1A60(&D_00221758, 3), func_004A1A60(&D_00221758, 4), D_00309840[0].f34,
                  D_00309840[0].target > D_00309840[0].current ? D_00309840[0].target : D_00309840[0].current, 0.0f);
}
