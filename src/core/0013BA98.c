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
} St_12F470;
extern St_12F470 D_001AF010[2][4];
extern Pd_12F2A0 *func_0013B8C8(s32, s32, Pd_12F2A0 *);

/* from rac3-decomp's func_0012F470 */
s32 func_0013BA98(s32 port, s32 slot)
{
    Pd_12F2A0 out;
    if (D_001AF010[port][slot].open == 0) {
        return 0x63;
    }
    func_0013B8C8(port, slot, &out);
    if (out.pad5C[0x14] == 6) {
        if (out.pad5C[0x15] == 2) {
            return 5;
        }
    }
    return out.pad5C[0x14];
}
