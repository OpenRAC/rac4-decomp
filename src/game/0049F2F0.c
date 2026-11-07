#include "common.h"

extern void func_0049C290(s32 param, s32 count);
extern void func_0049C400(s32 slot, s32 offset, s32 param_a, s32 param_b, s32 mode);
extern void func_0049CFE8(s32, s32, f32, f32, f32, f32);
extern void func_0049D280(s32 player, s32 count);
extern void func_0049D308(s32 arg0, s32 arg1, s32 arg2);
extern void func_0049F758(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_0049FA38(void);
extern void func_0049FBF0(s32);
extern u8 D_00307254[];

void func_0049F2F0(s32 arg0, s32 arg1) {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    u8 *e;
    s32 s;
    s32 t;
    s32 i;

    e = D_00307254 + (arg0 << 9);
    if (e[0x24] == 0) {
        e[0x24] = 1;
        *(s32 *)(e + 0x40) = arg1;
        if (*(*(u8 **)(e + 0x3C) + *(s32 *)(e + 0x2C) * 12) == 0) {
            for (i = 0; i < *(s32 *)(e + 0x30); i++) {
                if (*(*(u8 **)(e + 0x3C) + i * 12) != 0) {
                    *(s32 *)(e + 0x2C) = i;
                    break;
                }
            }
        }
        func_0049FBF0(arg0);
        s = arg0 << 6;
        t = s + 0x140002;
        func_0049D308(arg0, 0, t);
        func_0049C400(arg0, 0, t, s + 0x140003, 0);
        func_0049FA38();
        func_0049F758(arg0, &x0, &y0, &x1, &y1);
        func_0049CFE8(arg0, 0, x0, y0, x1, y1);
        func_0049D280(arg0, 1);
        func_0049C290(arg0, 1);
    }
}
