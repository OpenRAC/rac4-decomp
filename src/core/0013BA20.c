/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 data[0x58];
    s32 frame;
    u8 pad5C[0x80 - 0x5C];
} Pd_12F2A0;
typedef struct {
    u8 pad0[0x10];
    s32 open;
    u8 pad14[0x1C - 0x14];
} St_12F3F8;
extern St_12F3F8 D_001AF010[2][4];
extern void func_0011A370(void *, void *, s32);
extern void func_0013B8C8(s32, s32, void *);

/* from rac3-decomp's func_0012F3F8 */
s32 func_0013BA20(s32 port, s32 slot, void *dst) {
    Pd_12F2A0 out;
    if (D_001AF010[port][slot].open == 0) {
        return 0;
    }
    func_0013B8C8(port, slot, &out);
    func_0011A370(dst, &out, ((s32 *)&out)[0x18]);
    return ((s32 *)&out)[0x18];
}
