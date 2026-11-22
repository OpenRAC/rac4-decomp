#include "common.h"
typedef struct O { char _p0[0x20]; u8 f20; char _p21[0xBC - 0x21]; s16 fBC; } O;
extern O *D_0039D230[];
s32 func_L01_0047EDC8(s32 arg0) {
    O *o = D_0039D230[arg0];
    if (o == NULL || o->f20 == 0xFE || o->f20 == 0xFD) {
        return 1;
    }
    return o->fBC != 0x20AB;
}
