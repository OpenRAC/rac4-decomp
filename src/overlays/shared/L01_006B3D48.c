/* cflags: -mno-split-addresses */
#include "common.h"

extern void *func_L01_006B3DA0(void *);
extern void *func_00488C98(void *);
extern u32 D_00222D2C[];

/* from rac3-decomp's func_L39_0066C828 */
s32 func_L01_006B3D48(void *src) {
    if ((u32)src < D_00222D2C[0]) {
        return (s32)func_L01_006B3DA0(src);
    }
    return (*(s32 (**)(void *))((u8 *)func_00488C98(src) + 4))(src);
}
