/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Move one byte between `data` and the 0x8 write cursor of the ring buffer:
// op 1 writes `data` to the cursor, op 2 reads the cursor into `data`.
s32 func_01EAA218(s32 op, u8 *p, u8 *data) {
    u8 *read;
    u8 *write;

    if (*(s32 *)(p + 0x10) != 0) {
        return 0;
    }
    read = *(u8 **)(p + 0x4);
    if (*(u8 **)(p + 0x8) >= read) {
        *(s32 *)(p + 0x10) = 2;
        return 0;
    }
    if (*(u8 **)(p + 0x8) == 0) {
        *(s32 *)(p + 0x10) = 2;
        return 0;
    }
    if (read == *(u8 **)(p + 0x8)) {
        *(s32 *)(p + 0x10) = 8;
        return 0;
    }
    if (op == 1) {
        *(*(u8 **)(p + 0x8)) = *data;
    } else if (op == 2) {
        *data = *(*(u8 **)(p + 0x8));
    }
    write = *(u8 **)(p + 0x8) + 1;
    *(u8 **)(p + 0x8) = write;
    return 1;
}
