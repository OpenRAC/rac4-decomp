#include "common.h"

extern s32 D_00222380;
extern u8 D_00244F00[];
extern void func_005CB580();

// Call every registered 0xC-byte handler, then run func_005CB580.
void func_L00_005CB508(void) {
    s32 i;

    for (i = 0; i < D_00222380; i++) {
        u8 *e = D_00244F00 + i * 0xC;
        void (*handler)(s32, u8) = *(void (**)(s32, u8))e;

        if (handler != 0) {
            handler(*(s32 *)(e + 0x4), *(e + 0x8));
        }
    }
    func_005CB580();
}
