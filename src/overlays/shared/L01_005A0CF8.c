#include "common.h"

extern void *func_L00_005EAC30(void *);
extern void func_L00_005EB6C0(void *, s32);
extern void func_L00_0066CC68(s32, s32);
extern void func_L01_00550A08(void *, s32, void *, s32, s32, s32, s32, s32);
extern s32 D_222B20;

/* Looks up a record, decrements its counter while positive, then starts a transfer or clears it and reports whether the counter is still positive. */
s32 func_L01_005A0CF8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *rec;
    s32 var_v0;

    rec = func_L00_005EAC30((void *)arg0);
    var_v0 = 0;
    if (rec != NULL) {
        if (*(s16 *)(rec + 0x26) > 0) {
            *(s16 *)(rec + 0x26) = (s16)(*(u16 *)(rec + 0x26) - 1);
        }
        if (arg1 != 0 && *(s16 *)(rec + 0x26) > 0) {
            func_L01_00550A08(&D_222B20, arg0, rec + 0x40, arg2, 10, 20, 0x7F7F2000, 1);
        } else {
            func_L00_005EB6C0((void *)arg0, 0);
            func_L00_0066CC68(2, arg0);
        }
        var_v0 = *(s16 *)(rec + 0x26) > 0;
    }
    return var_v0;
}
