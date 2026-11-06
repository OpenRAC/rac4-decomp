#include "common.h"

typedef struct { u8 pad[0x10]; s32 v; u8 rest[0x54 - 0x14]; } Rec;
extern Rec D_002F32B8[];

/* Word 0x10 of record i of the 0x54-byte table D_002F32B8 for i below 4, else -1. */
s32 func_00497848(u32 i) {
    if (i < 4) {
        return D_002F32B8[i].v;
    }
    return -1;
}
