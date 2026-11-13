/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 *p;
    s32 r;
} FILE_;

s32 func_0011AB04(u8 *);
u8 *func_0011C3E8(u8 *, s32, FILE_ *);

s32 func_L00_0053C260(u8 *arg0, s8 *arg1, s32 arg2) {
    s32 value = 0;

    *arg1 = 0;
    func_0011C3E8(arg1, arg2, *(FILE_ **)(arg0 + 0x20));
    if (*arg1 != 0) {
        value = func_0011AB04(arg1);
    }
    return value;
}
