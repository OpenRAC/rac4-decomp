/* Not matching yet: SIZE ours 136 / retail 144 (tools/try_func.py func_01EAA218 --diff). Not part of the build. */
#include "common.h"

// Move one byte between the source buffer and the 0x8 write cursor.
s32 func_01EAA218(s32 op, u8 *p, u8 *data) {
    u8 *read;
    u8 *write;

    if (*(s32 *)(p + 0x10) != 0) {
        return 0;
    }
    read = *(u8 **)(p + 0x4);
    write = *(u8 **)(p + 0x8);
    if (write >= read) {
        *(s32 *)(p + 0x10) = 2;
        return 0;
    }
    if (write == 0) {
        *(s32 *)(p + 0x10) = 2;
        return 0;
    }
    if (read == write) {
        *(s32 *)(p + 0x10) = 8;
        return 0;
    }
    if (op == 1) {
        *write = *data;
    } else if (op == 2) {
        *data = *write;
    }
    write = *(u8 **)(p + 0x8) + 1;
    *(u8 **)(p + 0x8) = write;
    return 1;
}
