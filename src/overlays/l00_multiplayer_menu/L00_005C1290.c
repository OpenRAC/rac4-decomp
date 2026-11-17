#include "common.h"

u8 D_0021E5BC = 0;
u8 D_0021E5BD = 0;
u16 *D_0021E5C0 = 0;

/* Maps a character code from 0x80 up through a half-word table, byte-swapping it when a flag is set. */
s16 func_L00_005C1290(s32 arg0) {
    s32 v = arg0;
    u32 temp;
    u32 temp_a0;

    if (arg0 >= 0x80) {
        if (D_0021E5BC != 0) {
            temp = D_0021E5C0[arg0 - 0x21];
            temp_a0 = temp << 16;
            v = (s16)temp;
            if (D_0021E5BD != 0) {
                v = ((v & 0xFF) << 8) | (temp_a0 >> 24);
            }
        }
    }
    return v;
}
