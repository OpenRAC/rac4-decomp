/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_00528C38(u8 *key, unsigned long *k);

typedef struct {
    s64 w[48];
} Type1;

/* Copies an 8-byte value into the object, keys two blocks and duplicates the first block. */
void func_L00_00519A00(void *arg0, void *arg1, void *arg2) {
    u8 *ctx = *(u8 **)((u8 *)arg0 + 0x78);

    if (arg2 != 0) __builtin_memcpy((u8 *)arg0 + 0x0C, arg2, 8);
    __builtin_memcpy((u8 *)arg0 + 0x2C, (u8 *)arg0 + 0x0C, 8);
    if (arg1 != 0) {
        func_L00_00528C38(arg1, (unsigned long *)ctx);
        func_L00_00528C38((u8 *)arg1 + 8, (unsigned long *)(ctx + 0x180));
        *(Type1 *)(ctx + 0x300) = *(Type1 *)ctx;
    }
}
