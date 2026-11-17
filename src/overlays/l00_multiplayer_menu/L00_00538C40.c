/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00538098(void *, s32);
extern void *func_L00_005383D0(void *a, void *b);
extern int func_L00_00538508(void *a, s32 w);

/* Dispatches on two operand kinds, else forwards to a virtual method. */
s32 func_L00_00538C40(s32 **a0, void *a1, s32 *a2, s32 *a3, s32 a4, s32 a5)
{
    if (a2[1] == 0 || (a2[1] == 1 && *(s64 *)a2[0] == 0)) {
        func_L00_00538508(a1, 0);
        return 0;
    }
    if (a3 != 0) {
        if (a3[1] == 0 || (a3[1] == 1 && *(s64 *)a3[0] == 0)) {
            func_L00_00538508(a1, 1);
            return 0;
        }
        if (a3[1] == 1 && *(s64 *)a3[0] == 1) {
            func_L00_005383D0(a1, a2);
            return 0;
        }
    }
    func_L00_00538098(a2, (*a0)[0]);
    return ((s32 (*)(void *, void *, void *, void *, s32))((*a0)[3]))(a0, a1, a2, a3, a5);
}
