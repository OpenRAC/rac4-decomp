/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_00403330(s32 a0, s32 a1, s32 a2);
extern void func_004074E8(s32 *p);

/* When both sides carry the same id, merge them and reset the target object;
   0x20D reports the mismatch. */
s32 func_004070B8(s32 arg0, s32 *a, s32 *b)
{
    s32 id = a[1];

    if (id != b[1]) {
        return 0x20D;
    } else {
        func_00403330(a[0], b[0], id);
        func_004074E8((s32 *)(arg0 + 0x10));
        return 0;
    }
}
