#include "common.h"

extern void func_L00_00607960(void *);

// Free the four handles of the object's sub-struct and set a byte by its field at 0x38.
void func_L01_00427EF0(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0xAC);
    s32 i;
    s32 *p = (s32 *)(s + 0x20);
    for (i = 3; i >= 0; i--) {
        if (*p != 0) {
            func_L00_00607960((void *)*p);
            *p = 0;
        }
        p++;
    }
    arg0[0x30] = (*(s32 *)(s + 0x38) > 0) ? 0xFF : 0x40;
}
