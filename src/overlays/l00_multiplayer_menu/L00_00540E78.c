/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_004FAD28(s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);

// Refresh the cached resource for the owner's current id; returns 0 if it cannot be acquired.
s32 func_L00_00540E78(s32 *arg0) {
    s32 *owner;
    arg0[1] = 0;
    owner = (s32 *)arg0[0];
    if (owner != 0 && arg0[2] != owner[14]) {
        if (arg0[3] != 0) {
            func_0011A518((void *)arg0[3], 0, arg0[2]);
            func_004FAD28(arg0[3]);
            owner = (s32 *)arg0[0];
        }
        arg0[3] = (s32)func_L00_004FACD8(owner[14]);
        if (arg0[3] == 0) {
            func_L00_004F84C8(6, 0x74, 0x21, 0, 0);
            return 0;
        }
        arg0[2] = ((s32 *)arg0[0])[14];
    }
    if (arg0[3] != 0) {
        func_0011A518((void *)arg0[3], 0, arg0[2]);
    }
    return 1;
}
