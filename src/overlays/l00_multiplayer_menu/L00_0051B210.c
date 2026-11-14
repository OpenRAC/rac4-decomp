/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_00540E58(s32 arg0);
extern void func_L00_00519578(s32 arg0, s32 arg1, u32 arg2);
extern void func_L00_005195A8(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_L00_00540F30(s32 arg0, s32 arg1);

/* Looks up the record at arg0 and, when found, stores arg1 and arg2 through it; returns 1 on success. */
s32 func_L00_0051B210(s32 *arg0, s32 arg1, s32 arg2) {
    s32 buf[8];
    s32 sp20;

    func_00540E58(arg0[0]);
    func_L00_005195A8(arg0[1], buf, &sp20);
    if (func_L00_00540F30(arg0[1], arg0[3]) == 0) {
        return 0;
    }
    func_L00_00519578(arg0[1], buf, sp20);
    func_L00_005195A8(arg0[1], arg1, arg2);
    return 1;
}
