#include "common.h"

extern void func_L00_0069DC48(s32);
extern void func_L00_0071A058(void *);

// Runs the object's virtual method at 0x1C, with two flag-dependent calls around it.
void func_L00_00718BE0(u8 *a0) {
    if (*(void **)(a0 + 0x108) != NULL) {
        if (*(u8 *)(*(u8 **)(a0 + 0x108) + 0xA9) == 1) {
            func_L00_0069DC48(4);
        }
        (*(void (**)(void *))(*(u8 **)(*(u8 **)(a0 + 0x108) + 0x58) + 0x1C))(*(void **)(a0 + 0x108));
        if (*(u8 *)(*(u8 **)(a0 + 0x108) + 0xA9) == 1) {
            func_L00_0069DC48(0);
        }
    }
    func_L00_0071A058(a0);
}
