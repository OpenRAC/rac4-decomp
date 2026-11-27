/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011A370();
extern s32 D_00169D38;
extern u8 D_1B76C0[];
extern u8 D_1B7788[];

void func_01ED56B8(s32 arg0, u8 *arg1) {
    D_00169D38 = arg0;
    switch (arg0) {
    case 0x2D:
        func_0011A370(D_1B76C0, arg1, 0xC4);
        return;
    case 0x12:
        func_0011A370(D_1B7788, arg1, 0xEC);
        break;
    }
}
