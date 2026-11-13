#include "common.h"
u8 *func_0047DE20(void);
typedef struct Type1 { u8 p00[0x1C0]; s32 f1C0[4]; } Type1;
s32 func_L01_005A9868(u32 arg0) {
    s32 result;
    if (arg0 >= 4U) {
        result = 0;
    } else {
        Type1 *context = (Type1 *)func_0047DE20();
        result = context->f1C0[arg0];
    }
    return result;
}
