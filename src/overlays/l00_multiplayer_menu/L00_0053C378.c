/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 *func_0011A1A0(void);
s32 func_0012B980(s32, s32, s32);
s32 func_005419D8(s32);
void func_L00_004F7200(void *);
void func_L00_004F7228(void *);
s32 func_L00_0053C378(void *arg0, s32 arg1, s32 arg2) {
    s32 value = 0;
    if (arg1 != 0) {
        *func_0011A1A0() = 0;
        value = func_0012B980(*(s32 *)((u8 *)arg0 + 0x1C), arg1, arg2);
        func_L00_004F7228(arg0);
        if (value <= 0 && func_005419D8(value) != 0) {
            func_L00_004F7200(arg0);
        }
    }
    return value;
}
