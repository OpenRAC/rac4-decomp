/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004E4970 (src/levels/39_multiplayer_menu/L39_004E4970.c, GPL-3.0), the same code in both games. */

extern s32 func_L00_00520770(s32, s32 *, s32);
typedef struct V_004E4970 { s32 f0; s32 count; s32 cap; s32 *items; } V_004E4970;
extern s32 func_L00_00520850(s32, s32, s32, s32);
extern s32 func_L00_005206E8(V_004E4970 *, s32);
extern s32 *func_L00_00541590(void);
extern s32 func_L00_005415E0(s32 *, s32 *, s32);
s32 func_L00_00520770(s32 arg0, s32 *arg1, s32 arg2) {
    V_004E4970 *v = (V_004E4970 *)arg0;
    s32 *item;
    s32 r;
    if (arg2 & 0x10) {
        func_L00_00520850(arg0, arg1[0], arg1[1], 0);
    }
    if (v->cap <= v->count) {
        r = func_L00_005206E8(v, v->count + 4);
        if (r != 0) {
            return r;
        }
    }
    if ((arg2 & 8) == 0) {
        item = func_L00_00541590();
        if (item == 0) {
            return 1;
        }
        r = func_L00_005415E0(item, arg1, arg2);
        if (r != 0) {
            return r;
        }
        arg1 = item;
    }
    v->items[v->count++] = (s32)arg1;
    return 0;
}
