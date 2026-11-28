/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern const u8 D_L00_004AF830[];

s32 func_L00_00529080(const u8 *key) {
    u32 i = 0;

    do {
        u8 value = key[i];
        if (value != D_L00_004AF830[value])
            return 0;
    } while (++i < 8);
    return 1;
}
