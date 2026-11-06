#include "common.h"

extern s32 func_L00_006AA100(s32);

s32 func_L01_00690998(u8 *arg0) {
    if (arg0 != NULL) {
        return func_L00_006AA100(*(s32 *)(arg0 + 0x90));
    }
    return 0;
}
