/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 *D_00222794;
extern u8 *D_002227B0;

s32 func_L41_003E06F8(s32 arg0, u8 *obj, s32 result) {
    u8 *p;
    s32 i;

    if (*(s16 *)(obj + 0xBC) == 0x2075) {
        result = *(s32 *)(*(u8 **)(obj + 0xAC) + 0x2EC);
    } else {
        for (p = D_00222794, i = 0; p != D_002227B0; p += 0x100, i++) {
            if (p == obj) {
                result = i;
                break;
            }
        }
    }
    return result;
}
