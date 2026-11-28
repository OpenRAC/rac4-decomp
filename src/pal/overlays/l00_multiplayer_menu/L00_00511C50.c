/* cflags: @ee296 -O2 -G0 -Wa,-G0 */
#include "pal/l00_random.h"

extern s32 func_L00_004F0DA0(u8 *data);

static inline s32 compare_config_field(s32 expected, s32 shift) {
    union {
        u16 value;
        u8 bytes[2];
    } data;
    u8 *bytes;
    s32 result;
    u32 i;

    func_L00_004F0DA0(data.bytes);
    result = (((u32)data.value >> shift) & 7) == expected;
    bytes = data.bytes;
    for (i = 0; i < 2; i++) {
        bytes[i] = random_byte();
    }
    return result;
}

s32 func_L00_00511C50(s32 expected) {
    return compare_config_field(expected, 11);
}

s32 func_L00_00511D40(s32 expected) {
    return compare_config_field(expected, 8);
}
