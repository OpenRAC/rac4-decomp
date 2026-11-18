/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[0x40]; } Blk_40;

extern u8 *D_0016819C;

/* Copies two 0x40-byte blocks, taken from the buffer that D_0016819C points to, to arg0 and arg1 (unaligned). */
void func_01EB4A28(Blk_40 *arg0, Blk_40 *arg1) {
    *arg0 = *(Blk_40 *)(D_0016819C + 0x184);
    *arg1 = *(Blk_40 *)(D_0016819C + 0x1C4);
}
