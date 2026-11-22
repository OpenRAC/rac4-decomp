#include "common.h"
extern s32 D_00222DD4;
extern s16 D_0032C600[];
s32 func_L00_00670610(s16 arg0) {
    u8 i;
    for (i = 0; i < D_00222DD4; i++) {
        if (D_0032C600[i] == arg0) {
            return i;
        }
    }
    return 0xFF;
}
