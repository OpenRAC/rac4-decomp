/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(void *);

// Free the object's buffers and clear its fields.
s32 func_L00_00515D90(u8 *arg0) {
    u8 *p;
    s32 v;

    if (arg0 == 0) {
        return 0;
    }
    p = *(u8 **)(arg0 + 0x20);
    v = *(s32 *)(p + 0x8);
    if (v != 0) {
        func_004FAD28((void *)v);
    }
    v = *(s32 *)(p + 0x14);
    if (v != 0) {
        func_004FAD28((void *)v);
    }
    func_004FAD28(*(void **)(arg0 + 0x20));
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    return 1;
}
