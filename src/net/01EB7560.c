/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EBDF10(s32 arg0, u8 *arg1, s32 arg2, u32 *arg3, u32 *arg4, u32 *arg5);

typedef struct { s32 f0; u8 *f4; u8 *f8; u8 pad[0x44]; } Type2;
typedef struct { void *f0; u8 pad[0x180]; Type2 *f184; u8 pad2[0x14]; u16 f19C; } Type1;

/* Adds the sizes of the two entries of record arg1 into the totals arg2..arg5; 2 on bad arguments, else 0. */
s32 func_01EB7560(Type1 *arg0, u16 arg1, u32 *arg2, u32 *arg3, u32 *arg4, u32 *arg5) {
    u32 sp0 = 0;
    u32 sp4 = 0;
    u32 sp8 = 0;

    if (arg0 == NULL) return 2;
    if (arg1 >= arg0->f19C) return 2;
    if (arg2 == NULL) return 2;
    if (arg4 == NULL) return 2;
    if (arg3 == NULL) return 2;
    if (arg5 == NULL) return 2;
    *arg3 = 0;
    *arg2 = 0;
    *arg5 = 0;
    *arg4 = 0;
    if (arg0->f184[arg1].f4 != NULL) {
        if (func_01EBDF10((s32) arg0->f0, arg0->f184[arg1].f4, 0, &sp0, &sp4, &sp8) != 0) return 0;
        *arg3 += sp0;
        *arg2 += sp4;
        if (func_01EBDF10((s32) arg0->f0, arg0->f184[arg1].f4, 1, &sp0, &sp4, &sp8) != 0) return 0;
        *arg5 += sp0;
        *arg4 += sp4;
    }
    if (arg0->f184[arg1].f8 != NULL) {
        if (func_01EBDF10((s32) arg0->f0, arg0->f184[arg1].f8, 0, &sp0, &sp4, &sp8) != 0) return 0;
        *arg3 += sp0;
        *arg2 += sp4;
        if (func_01EBDF10((s32) arg0->f0, arg0->f184[arg1].f8, 1, &sp0, &sp4, &sp8) != 0) return 0;
        *arg5 += sp0;
        *arg4 += sp4;
    }
    return 0;
}
