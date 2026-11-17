/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(s32);
extern void func_L00_00547500(void *arg0);

// Release the three owned blocks of an object, then the object itself.
s32 func_L00_0053B250(void *self) {
    func_L00_00547500(*(void **)((u8 *)self + 0x10));
    if (*(s32 *)((u8 *)self + 0x14) != 0) {
        func_004FAD28(*(s32 *)((u8 *)self + 0x14));
    }
    if (*(s32 *)((u8 *)self + 0x18) != 0) {
        func_004FAD28(*(s32 *)((u8 *)self + 0x18));
    }
    func_004FAD28((s32)self);
    return 0;
}
