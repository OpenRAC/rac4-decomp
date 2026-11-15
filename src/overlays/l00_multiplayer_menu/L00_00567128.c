/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_00126A90(void);
extern int func_00126BB0();
extern s32 func_L00_00566950(void);
extern void func_L00_005669C0(void);
extern void func_L00_005670A8(u8 *a0);
extern s32 D_004A9B90[];
extern s32 D_004A9B94[];
extern void *D_004A9B98[];

/* Removes the list entry whose id is arg0 (every entry when arg0 is -1), then resets D_004A9B90 when the count is not positive. */
s32 func_L00_00567128(s32 arg0) {
    s32 s0;
    s32 count;
    u8 *a0;

    s0 = arg0;
    if (s0 == 0) {
        s0 = func_00126A90();
    }
    if (func_L00_00566950() < 0) {
        return -1;
    }
    if (s0 == -1) {
        a0 = (u8 *)D_004A9B98[0];
        while (a0 != NULL) {
            func_L00_005670A8(a0);
            a0 = (u8 *)D_004A9B98[0];
        }
    } else {
        a0 = (u8 *)D_004A9B98[0];
        while (a0 != NULL) {
            if (s0 == *(s32 *)(a0 + 0x8)) {
                func_L00_005670A8(a0);
                break;
            }
            a0 = *(u8 **)(a0 + 0x0);
        }
    }
    count = D_004A9B94[0];
    if (count <= 0) {
        func_00126BB0(D_004A9B90[0]);
        D_004A9B90[0] = -1;
        return 0;
    }
    func_L00_005669C0();
    return 0;
}
