/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_L01_0064EA50(unsigned char *object, s32 arg1);
extern void func_L01_0064EAC0(s32, s32);
extern u8 *D_222D14;

// Releases the two groups of object ids held by the object's data block.
void func_L01_004903B8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0xAC);
    s32 *q;
    s32 i = 1;

    *(s32 *)(p + 0x48) = 0;
    q = (s32 *)(p + 0x30);
    do {
        if (*q != -1) {
            func_L01_0064EA50((u8 *)(*q << 8) + (s32)D_222D14, 0);
        }
        q++;
        i--;
    } while (i >= 0);
    q = (s32 *)(p + 0x38);
    i = 1;
    do {
        s32 v = *q;
        q++;
        func_L01_0064EAC0(v, 0);
        i--;
    } while (i >= 0);
}
