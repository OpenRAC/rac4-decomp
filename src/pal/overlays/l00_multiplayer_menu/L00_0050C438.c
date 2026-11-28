/* cflags: @ee296 -O2 -G0 -Wa,-G0 */
#include "pal/l00_random.h"

extern u8 D_L00_0049E540[];

void func_L00_0050C438(u8 *buffer) {
    s32 i;
    s32 j;

    for (i = 0; i < 16; i++) {
        buffer[i] = random_byte();
    }
    for (j = 0; j < 16; j++) {
        buffer[j] ^= D_L00_0049E540[j];
    }
}
