/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_00167C7C[];
extern s32 D_00167C80[];
extern s32 func_0013A7A0(s32 nonblocking, s32 *command, s32 *result);
extern s32 func_00126BB0(s32 semaphore);

s32 func_0013A0F0(void)
{
    if (D_00167C7C[0] >= 0) {
        func_0013A7A0(0, 0, 0);
        func_00126BB0(D_00167C7C[0]);
        D_00167C7C[0] = -1;
        func_00126BB0(D_00167C80[0]);
    }
    return 1;
}
