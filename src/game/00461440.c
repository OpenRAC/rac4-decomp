#include "common.h"
extern s32 func_00138E08(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_00138FF0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_00126E20(s32);
extern void func_00131A08(s32, s32);
extern int func_00139130(u64 *p1, u64 *p2);
extern int func_001392B0(u64 *p1, u64 *p2);
void func_00461440(u64 *a0, s32 a1, s32 a2, s32 a3)
{
    u64 buf1[12];
    u64 buf2[12];
    u64 pad[2];
    s32 w = a2 >> 6;
    s32 v = (0x400000 - a2 * a3) << 8 >> 16;
    if (w <= 0) w = 1;
    func_00138E08(buf1, v, w, 0x13, 0, 0, a2, a3);
    func_00126E20(0);
    func_00139130(buf1, a0);
    func_00131A08(0, 0);
    w = a2 >> 7;
    if (w <= 0) w = 1;
    func_00138FF0(buf2, v, w, 0, 0, 0, (a2 << 15) >> 16, (a3 << 15) >> 16);
    func_00126E20(0);
    func_001392B0(buf2, a0);
    func_00131A08(0, 0);
}
