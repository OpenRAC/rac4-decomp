#include "common.h"
extern void func_L01_00498CC8(void *, s32, s32);
extern u8 *D_00222D34;
void func_L01_00499260(void) {
    u8 *entry = D_00222D34;
    while (entry != 0) {
        if (*(s16 *)(entry + 0xBC) == 0x2682) func_L01_00498CC8(entry, 6, -1);
        entry = *(u8 **)(entry + 0x28);
    }
}
