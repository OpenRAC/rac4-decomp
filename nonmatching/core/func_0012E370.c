/* Not matching yet: SIZE ours 160 / retail 124 (@ee29, MMIO EE timer; excluded by policy) (tools/try_func.py func_0012E370 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0012D420();
extern s32 func_0012D470();
extern u64 D_00165D28;

u64 func_0012E370(void)
{
    s32 s = func_0012D420();
    u32 m;
    u64 t2;
    u64 s0;
    u32 t0;
    u64 sh;

    s0 = *(volatile u32 *)0x10001000;
    m = *(volatile u32 *)0x10001010;
    t2 = D_00165D28;
    if (m & 0x800) {
        s0 = *(volatile u32 *)0x10001000;
        t2 += 1;
    }
    t0 = m & 3;
    t2 <<= 16;
    s0 |= t2;
    sh = t0 ? 2 : 0;
    sh <<= t0;
    s0 <<= sh;
    if (s != 0) {
        func_0012D470();
    }
    return s0;
}
