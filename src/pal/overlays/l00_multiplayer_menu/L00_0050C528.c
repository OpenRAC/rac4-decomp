/* cflags: @ee296 -O2 -G0 -Wa,-G0 -fno-gcse */
#include "pal/l00_random.h"

extern u8 D_L00_0049E540[];
extern void func_L00_0050E768(u8 *data, s32 size, u8 *output);

/* Hash three blocks after masking the last two, then overwrite the temporary buffer. */
void func_L00_0050C528(const u8 *first, const u8 *second, u8 *output) {
    u8 data[48];
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    u8 *pair;
    u8 *base;
    u8 *start;
    u8 *middle;
    u8 *end;

    start = data;
    for (i = 0; i < 16; i++) {
        start[i] = first[i];
    }
    middle = data + 16;
    for (j = 0; j < 16; j++) {
        middle[j] = second[j];
    }
    end = data + 32;
    for (k = 0; k < 16; k++) {
        end[k] = first[k];
    }
    m = 0;
    pair = data + 32;
    for (; m < 16; m++, pair++) {
        u8 left = pair[-16];
        u8 right = pair[0];
        u8 mask = D_L00_0049E540[m];
        pair[-16] = left ^ mask;
        pair[0] = right ^ mask;
    }
    func_L00_0050E768(data, 48, output);
    base = data;
    for (n = 0; n < 48; n++) {
        base[n] = random_byte();
    }
}
