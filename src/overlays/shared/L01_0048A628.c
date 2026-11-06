#include "common.h"
s32 func_L01_0048A3B8(s32, void *, void *);     /* extern */
void *func_L01_00588BC0(s32);                       /* extern */

s32 func_L01_0048A628(s32 arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = func_L01_00588BC0((*(s32 *)((u8 *)(arg1) + 0x130)));
    if (temp_v0 != NULL) {
        if ((*(u8 *)((u8 *)(temp_v0) + 0x20)) == 1) {
            (*(s8 *)((u8 *)(arg1) + 0x1D6)) = 0;
            func_L01_0048A3B8(arg0, arg1, temp_v0);
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
