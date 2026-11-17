/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_01E9C460(void *, void *, s32 *, s32, void *, s32);
extern s32 func_01EB4D80(void *);
extern u8 D_001B26C0[];
extern u8 D_001B2700[];
s32 func_01EB5D90(s32 *arg0) {
    s32 buf[4];
    s32 x;
    func_0011A518(buf, 0, 0x10);
    if (func_01E9C460(D_001B26C0, D_001B2700, &x, 1, buf, 2) < 0) {
        return 0xC350;
    }
    *arg0 = func_01EB4D80(buf);
    return 0;
}
