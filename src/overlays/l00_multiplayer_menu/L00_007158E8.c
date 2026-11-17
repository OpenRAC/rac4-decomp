#include "common.h"

extern s32 func_0011AB04(u8 *);
extern void func_L00_007162A0(void *);

/* stores arg1 at +0xB78, measures it (or the buffer at +0xB7C when null) into +0xF7C, then calls func_L00_007162A0 */
void func_L00_007158E8(u8 *arg0, u8 *arg1) {
    *(u8 **)(arg0 + 0xB78) = arg1;
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0xF7C) = func_0011AB04(arg1);
    } else {
        *(s32 *)(arg0 + 0xF7C) = func_0011AB04(arg0 + 0xB7C);
    }
    func_L00_007162A0(arg0);
}
