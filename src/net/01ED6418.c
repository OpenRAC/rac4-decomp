/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01ED5DD0(s32, s32, s32, void *);
extern s32 D_00169CD0;
extern s32 D_00169CD4;

s32 func_01ED6418(char *arg0) {
    arg0[0x14] = 0;
    arg0[0x25] = 0;
    if (D_00169CD0 != 1) return -0xF;
    if (D_00169CD4 == 0) return -0x10;
    return (func_01ED5DD0(4, 0xA, 0x50, arg0) == 0) ? 0 : -5;
}
