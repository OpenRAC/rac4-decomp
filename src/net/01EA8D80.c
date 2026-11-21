/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EA76E8(void *arg0);
extern s32 D_1B23B0[];

// Release the held handle if one is active: 0 on success, 5 if none.
s32 func_01EA8D80(void) {
    s32 *p = D_1B23B0;
    if (p[0] != 0) {
        func_01EA76E8((void *)p[1]);
        p[0] = 0;
        return 0;
    }
    return 5;
}
