/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_004A3B30[];
extern s32 D_004A3B34[];
extern s32 D_004A3B38[];
extern s32 D_004B0B28[];
extern s32 D_004B0B30[];
extern s32 D_004B0B38[];
extern s32 func_L00_00560B50();
extern s32 func_L00_00561548();
extern void func_L00_00556FD8();

/* sets up globals, runs a call with a local buffer, then a follow-up call on success */
void func_L00_00556F28(s32 arg0, s32 arg1, s32 arg2) {
    s32 buf[4];
    s32 r;
    s32 *p34 = D_004A3B34;
    s32 *p38 = D_004A3B38;

    D_004A3B30[0] = arg2;
    *p34 = 0;
    *p38 = arg0;
    r = func_L00_00560B50(D_004B0B28, D_004B0B30, D_004B0B38, buf, func_L00_00556FD8);
    *p38 = arg0;
    *p34 = 0;
    if (r >= 0) {
        buf[0] = func_L00_00561548(arg2, arg1);
    }
}
