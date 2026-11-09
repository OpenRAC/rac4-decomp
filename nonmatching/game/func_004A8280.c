/* Not matching yet: BYTES 31/292 (tools/try_func.py func_004A8280 --diff). Not part of the build. */
/* cflags: -O2 -fno-gcse */
/* Note: the cflags above were a diagnostic experiment; a landable version must build with the file's normal flags. */
#include "common.h"

extern s32 func_00498670(void *a, s32 b, s32 c, f32 x);
extern s32 func_00498918(s32, s32);
extern s32 func_004989C0(s32 a0, s32 a1);
extern s32 func_004A1A60(void *arg0, s32 arg1);
extern void func_00505328(s32, s32);
extern s32 func_00505B20(void);
extern char D_00221650[];
extern char D_00308108[];

void func_004A8280(void)
{
    s32 color = 0x40000000;
    s32 idx = func_00505B20();
    char *p = D_00308108 + idx * 0xB8;
    s32 n = *(s32 *)(p + 0xC);
    s32 c;

    if (n != 0) {
        if (n > 0) {
            c = func_00498918(0, 1);
        } else {
            c = func_00498918(1, 1);
        }
        color = func_00498670(p + 0x10, 0x40000000, (c & 0xFFFFFF) | 0x40000000, 0.01f);
    }
    func_00505328(func_004A1A60(D_00221650, 0x2C), color);
    color = 0x80D0D0D0;
    if (*(s32 *)(p + 0x74) <= 0 && *(s32 *)(p + 0x94) > 0) {
        color = func_00498670(p + 0x14, func_004989C0(idx, 0), 0x80D0D0D0, 0.05f);
    }
    func_00505328(func_004A1A60(D_00221650, 0x30), color);
}
