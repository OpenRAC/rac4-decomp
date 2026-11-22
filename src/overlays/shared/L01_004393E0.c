/* cflags: @ee29 -O2 -G8 */
#include "common.h"

s32 D_002214B0;
s32 D_002214B8;
extern s32 D_003A63A0[];

s32 *func_L01_004393E0(s32 a0, s32 type, s32 *out) {
    switch (type) {
    case 0xD:
        *out = 4;
        return &D_002214B0;
    case 0xE:
        *out = 0x1C;
        return D_003A63A0;
    case 0xF:
        *out = 0x10;
        return &D_002214B8;
    default:
        return 0;
    }
}
