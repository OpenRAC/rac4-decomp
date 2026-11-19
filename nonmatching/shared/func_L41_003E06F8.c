/* Not matching yet: BYTES 33/100 (tools/try_func.py func_L41_003E06F8 --diff). Not part of the build. */
#include "common.h"

extern u8 *D_00222794;
extern u8 *D_2227B0[];

s32 func_L41_003E06F8(s32 arg0, u8 *obj, s32 result) {
    u8 *p;
    u8 *end;
    s32 i;

    if (*(s16 *)(obj + 0xBC) == 0x2075) {
        return *(s32 *)(*(u8 **)(obj + 0xAC) + 0x2EC);
    }
    end = D_2227B0[0];
    for (p = D_00222794, i = 0; p != end; p += 0x100, i++) {
        if (p == obj) {
            result = i;
            break;
        }
    }
    return result;
}
