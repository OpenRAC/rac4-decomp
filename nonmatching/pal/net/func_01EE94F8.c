/* Not matching yet: 20/25 (80.00%) relocation-masked positional words; 100/100 candidate/target bytes. Callee func_01EF0748 argument contract conflicts with its published void prototype; requires reconciliation. Reproduce: python tools/check_func.py --version pal func_01EE94F8 nonmatching/pal/net/func_01EE94F8.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"
void func_01EE66B0(s32, s32);
void func_01EE9B40(s32);
s32 func_01EEE12C(void);
void func_01EF0748();
void func_01F0C090(char *, s32);
extern char D_0019B4E0;

s32 func_01EE94F8(s32 arg0) {
    if (arg0 != *(s32 *)(func_01EEE12C() + 0xA8)) {
        func_01F0C090(&D_0019B4E0, 2475);
    }
    *(s32 *)(arg0 + 0x3A30) = 0;
    func_01EF0748(arg0 + 0x3AD8);
    func_01EE9B40(arg0);
    func_01EE66B0(arg0, 0);
    return 1;
}
