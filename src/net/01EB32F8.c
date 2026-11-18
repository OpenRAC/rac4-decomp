/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA90F0(s32);
extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A518(void *, s32, s32);
extern s32 func_01EA8F98(s32 *arg0);
extern s32 func_01EA94D0(s32 *out, s64 id);
extern void *func_01EB2F20();
extern void func_01EB2FF0(void *arg0, void *arg1);
extern void *func_01EB3028(s32, s32);

/* Looks up or creates the buffer entry for an id and copies data into its slot. */
s32 func_01EB32F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 *s0;
    s32 temp;

    temp = func_01EA90F0(arg0);
    if (temp == 0) {
        return -1;
    }
    s0 = func_01EB3028(temp, arg1);
    if (func_01EA8F98((s32 *)arg2) != 0) {
        if (s0 != NULL && s0[4] != 0) {
            func_0011A518((void *)s0[4], 0, 0x40);
        }
        return 0;
    }
    if (s0 == NULL) {
        s0 = func_01EB2F20();
        s0[2] = arg1;
        func_01EB2FF0((void *)temp, s0);
    }
    if (s0[4] == 0) {
        func_01EA94D0(s0 + 4, 0x40);
    }
    func_0011A370((u8 *)s0[4], (u8 *)arg2, 0x40);
    return 0;
}
