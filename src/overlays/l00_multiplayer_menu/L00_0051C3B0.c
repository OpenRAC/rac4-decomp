/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 D_004A03AC[];
extern s32 *D_004A03BC[];
extern void *func_L00_004F8B28();
extern void func_004FAD28(s32);

// Looks up an entry, calls the table handler for its index, then releases the entry.
s32 func_L00_0051C3B0(s32 arg0, s32 arg1) {
    s32 buf[3];
    s32 *p;
    s32 *t;
    void (*fn)(s32, s32, s32);

    if (D_004A03AC[0] == 0) {
        return 0;
    }
    arg1 = arg1 & 0xFFFF7FFF;
    buf[2] = arg0;
    buf[0] = arg1;
    p = func_L00_004F8B28(D_004A03AC[0], buf);
    if (p != 0) {
        t = D_004A03BC[0];
        if (t != 0 && arg1 < t[0]) {
            fn = (void (*)(s32, s32, s32))((s32 *)t[1])[arg1];
            fn(p[2], p[0], p[3]);
        }
        func_004FAD28((s32)p);
        return 1;
    }
    return 0;
}
