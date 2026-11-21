/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Copies the pending records of a 64-slot ring into dst from its read index, advancing the index, and returns the bytes copied. */
extern void func_0011A370(u8 *, u8 *, s32);

s32 func_01ED3D48(u8 *arg0, void **arg1, u8 *arg2, u32 arg3) {
    s32 total;
    s32 start;
    s32 idx;
    u32 size;
    u8 *rec;

    total = 0;
    if (arg0 == NULL) {
        return total;
    }
    idx = *(s32 *)(arg0 + 8) & 0x3F;
    start = idx;
    *arg1 = *(void **)(arg0 + 4);
    if (*(s32 *)arg0 == 1) {
        return total;
    }
    while (arg3 != 0
           && (rec = arg0 + (idx << 8) + 0x10, size = *(u32 *)(rec + 4), arg3 >= size)) {
        if (size != 0) {
            func_0011A370(arg2 + total, rec + 8, size);
            total += size;
            *(s32 *)(rec + 4) = 0;
            arg3 -= size;
            *(s32 *)(arg0 + 0xC) -= 1;
            *(s32 *)(arg0 + 8) = *(s32 *)rec + 1;
        } else if (*(s32 *)arg0 != 2) {
            return total;
        }
        idx = (idx + 1) & 0x3F;
        if (idx == start) {
            break;
        }
    }
    if (*(s32 *)arg0 == 2) {
        if (!(*(u32 *)(arg0 + 0xC) >= 0x30)) {
            *(s32 *)arg0 = 0;
        }
    }
    return total;
}
