/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern u8 D_191F01[];

typedef struct {
    s32 f0;
    s32 f4;
    s8 f8;
} Type1;

// Parses the digits of str into up to max table entries (f0 value, f4 digit limit, f8 key), returning how many were filled.
s32 func_L00_0052D030(s8 *str, s32 len, Type1 *table, s32 max) {
    s32 count = 0;
    s32 pos = 0;
    s32 c;
    s32 k;
    s32 sum;

    while (count < max && pos < len && (c = str[pos++]) != 0) {
        if (!(D_191F01[c] & 4)) {
            if (table[count].f8 == 0 || table[count].f8 == c) {
                table[count].f8 = c;
                k = 0;
                table[count].f0 = 0;
            } else {
                goto done;
            }
        } else {
            k = 1;
            table[count].f0 = c - 0x30;
        }
        while (k < table[count].f4) {
            if (pos >= len) {
                goto done;
            }
            c = str[pos++];
            if (c == 0) {
                goto done;
            }
            if (!(D_191F01[c] & 4)) {
                goto done;
            }
            k++;
            sum = table[count].f0 * 10 - 0x30;
            table[count].f0 = sum + c;
        }
        count++;
    }
done:
    return count;
}
