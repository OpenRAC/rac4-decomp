#include "common.h"

extern void func_00775158(s32 *);
extern u32 func_L00_0076CDB0(s32, void *, void *, s32 *);
extern void func_L00_00775200(s32 *arg0, u8 *arg1);
extern u8 *D_002233A4;
extern void func_L00_007752B8(void);

// Format a message into a stack buffer and submit it; return 1 when the submit did not fail.
s32 func_L00_00775238(s32 *arg0) {
    u8 buf[0x80];
    s32 result = 0;
    s32 handle = *(s32 *)(D_002233A4 + 0x40);
    func_L00_00775200(arg0, buf);
    if (func_L00_0076CDB0(handle, buf, func_L00_007752B8, arg0) != 0xFFFFFFFF) {
        result = 1;
        func_00775158(arg0);
    }
    return result;
}
