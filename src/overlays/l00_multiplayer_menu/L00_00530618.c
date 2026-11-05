/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_004FAD28(void *);
extern void func_005362F8(s32);
extern void func_00542440(s32);
extern s32 func_L00_004FAAF0(void *, s32, s32, void *, s32);
extern void func_L00_0052F258(s32);
extern u8 D_004AFCE8_[];
#define D_004AFCE8 ((u8 *)D_004AFCE8_)
void func_L00_00530618(s32 *arg0) {
    if (arg0 != 0) {
        if (func_L00_004FAAF0(arg0 + 5, -1, 3, D_004AFCE8, 0x6B) <= 0) {
            func_L00_0052F258(arg0[1]);
            func_00542440(arg0[2]);
            func_005362F8(arg0[3]);
            if (arg0[6] != 0) func_004FAD28((void *)arg0[6]);
            func_004FAD28(arg0);
        }
    }
}
