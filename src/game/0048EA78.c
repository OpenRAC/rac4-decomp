/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef int s128 __attribute__((mode(TI)));
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

extern void *D_002214D8;

/* Copy the indexed record's 16-byte field when the index is in range. */
void func_0048EA78(s32 arg0, s128 *arg1) {
    s32 index = arg0 & 0xFFFF;
    if ((D_002214D8 != NULL) && (M2C_FIELD(D_002214D8, s32 *, 0x3014) >= index)) {
        *arg1 = M2C_FIELD(((index << 5) + M2C_FIELD(D_002214D8, s32 *, 0x3018)), s128 *, 0x10);
    }
}
