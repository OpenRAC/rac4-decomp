/* Not matching yet: 7/26 (26.92%) relocation-masked positional words; 108/104 candidate/target bytes. One extra word; return type remains a hypothesis. Reproduce: python tools/check_func.py --version pal func_01EEF83C nonmatching/pal/net/func_01EEF83C.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -fno-schedule-insns -fno-schedule-insns2 -Wuninitialized */
#include "common.h"
extern s32 func_01F04E88(s32);
extern void func_01F04C2C(void *);
extern s32 func_01F0C090(void *, s32);
typedef struct Type1 Type1;
extern Type1 *D_0016E4B0[];
extern s32 D_0019C480[];
s32 func_01EEF83C(void) {
    void *p = D_0016E4B0[0];
    s32 v = func_01F04E88(88);
    s32 result;
    s32 *msg;
    s32 line;
    func_01F04C2C((void *)v);
    msg = D_0019C480;
    line = 1502;
    *(s32 *)((u8 *)p + 0x30D0) = v;
    result = *(s32 *)((u8 *)D_0016E4B0[0] + 0x30D0);
    if (result == 0) result = func_01F0C090(msg, line);
    return result;
}
