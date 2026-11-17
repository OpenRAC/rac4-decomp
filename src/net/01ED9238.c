/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01ED9230();
extern void func_01EDA950();

/* Runs the two helpers on the owner's object when the argument and its field are set, else returns -0x15. */
s32 func_01ED9238(s32 *arg0) {
    s32 *p;
    s32 s;

    if (arg0 == 0) {
        return -0x15;
    }
    if (arg0[1] == 0) {
        return -0x15;
    }
    p = (s32 *)arg0[0];
    s = p[1];
    if ((u32)p[6] >= 2) {
        func_01EDA950(s);
        func_01ED9230(s, arg0[1]);
    } else {
        func_01EDA950(s);
        func_01ED9230(s, arg0[1]);
    }
    return 0;
}
