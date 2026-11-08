/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    s32 open;
    u8 pad14[0x1C - 0x14];
} St_13C210;
extern St_13C210 D_001AF010[2][4];
extern s32 func_0013C0E0(s32, s32, s32);

/* from rac3-decomp's func_0012FC78 */
s32 func_0013C210(s32 port, s32 slot) {
    if (D_001AF010[port][slot].open == 0) {
        return 0;
    }
    return func_0013C0E0(port, slot, 0xFFF);
}
