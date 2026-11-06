/* cflags:  */
#include "common.h"
extern s64 func_L01_0049A4D8(void *, u64, s64);
extern u8 *D_00222E34;
void func_L01_0049A8E0(void) {
    u8 *entry = D_00222E34;
    while (entry != 0) {
        if (*(s16 *)(entry + 0xBC) == 0x2682) func_L01_0049A4D8(entry, 2, -1);
        entry = *(u8 **)(entry + 0x28);
    }
}
