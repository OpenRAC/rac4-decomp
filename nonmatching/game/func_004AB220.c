/* Not matching yet: BYTES 11/484 (tools/try_func.py func_004AB220 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 state;
    u8 pad04[0x18];
    s32 ids[(0x154 - 0x1C) / 4];
    f32 f154;
    s32 f158;
    u8 pad15C[0x10];
    s32 sel;
} Record;

extern Record D_00308B80[];
extern f32 D_00308B60[];

extern f32 func_00453BA0(f32);
extern s32 func_00498670(f32 *a, s32 b, s32 c, f32 x);
extern s32 func_004989C0(s32 a0, s32 a1);
extern s32 func_00504238(s32 handle, f32 a, f32 b);
extern void func_00504550(s32, void *, f32 *);
extern s32 func_00504B90(u32 id, f32 amount);
extern void func_00504F68(s32, s32);
extern void func_00505328(s32, s32);
extern s32 func_00505B20(void);

void func_004AB220(void)
{
    f32 x;
    f32 y;
    s32 idx;
    s32 a;
    s32 b;
    f32 *p;

    idx = func_00505B20();
    if (D_00308B80[idx].state == 6) {
        if (D_00308B80[idx].sel >= 0 && D_00308B80[idx].f158 != -1) {
            func_00504F68(0x70009, 1);
            func_00504F68(0x7000A, 1);
            func_00504550(0x70010 + D_00308B80[idx].ids[D_00308B80[idx].sel] * 8, &x, &y);
            func_00504238(0x70009, x, y);
            func_00504238(0x7000A, x, y);
            func_00504B90(0x70009, func_00453BA0(D_00308B60[2] * 1.2f));
            func_00504B90(0x7000A, func_00453BA0(-(D_00308B60[2] + D_00308B60[2])));
            a = func_004989C0(idx, 0);
            p = &D_00308B80[idx].f154;
            b = func_004989C0(idx, 1);
            func_00505328(0x70009, func_00498670(p, b, func_004989C0(idx, 3), 0.02f));
            func_00505328(0x7000A, a);
            return;
        }
    }
    func_00504F68(0x70009, 0);
    func_00504F68(0x7000A, 0);
}
