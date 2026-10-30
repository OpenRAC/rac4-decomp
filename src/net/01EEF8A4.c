#include "common.h"

extern s32 D_0016E430;
extern s32 func_01EEE13C();
extern void func_01EF0550(s32 arg0, s32 arg1);

// When the field at +0x30D0 of the object in D_0016E430 is set, pass it to func_01EF0550 with a value from func_01EEE13C, then clear it.
void func_01EEF8A4(void) {
    s32 v = D_0016E430;
    v = *(s32 *)(v + 0x30D0);
    if (v != 0) {
        func_01EF0550(func_01EEE13C(), *(s32 *)(D_0016E430 + 0x30D0));
        *(s32 *)(D_0016E430 + 0x30D0) = 0;
    }
}
