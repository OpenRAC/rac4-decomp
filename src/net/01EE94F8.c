/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_01EE66B0();
extern void func_01EE9B40(s32 arg0);
extern s32 func_01EEE12C(void);
extern void func_01EF0748();
extern void func_01F0C090(char *arg0, s32 arg1);
extern u8 D_0019B460[];

// Check the caller owns the object, clear its field 0x3A30, reset its sub-object and finish setup.
s32 func_01EE94F8(u8 *arg0) {
    if ((s32)arg0 != *(s32 *)(func_01EEE12C() + 0xA8)) {
        func_01F0C090((char *)D_0019B460, 0x9AB);
    }
    *(s32 *)(arg0 + 0x3A30) = 0;
    func_01EF0748(arg0 + 0x3AD8);
    func_01EE9B40((s32)arg0);
    func_01EE66B0(arg0, 0);
    return 1;
}
