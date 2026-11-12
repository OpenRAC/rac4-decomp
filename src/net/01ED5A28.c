/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011A518(void *, s32, s32);
extern s32 func_0011D5D8(const char *fmt, ...);
extern s32 func_01ED68A0(void *);
extern u8 D_001983A0[];
extern u8 D_1B78E0[];
extern s32 D_1BC84C;
extern void (*D_1BCA44)(void *, s32);

void func_01ED5A28(void) {
    u8 buf[0x1C];

    func_0011D5D8((const char *)D_001983A0);
    if (func_01ED68A0(D_1B78E0) != 0) {
        func_0011A518(buf, 0, 0x1C);
        *(s32 *)(buf + 0x18) = 0;
        if (D_1BCA44 != 0) {
            D_1BCA44(buf, D_1BC84C);
        }
    }
}
