/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 pad[0x50 - 12];
} Type2;

typedef struct Type1 {
    u8 pad0[0x184];
    Type2 *f184;
    u8 pad1[0x14];
    u16 f19C;
} Type1;

/* Sets *arg2 from entry arg1 of the table at arg0: -1 by default, 0 when f4 is set, 1 when only f8 is set; returns 2 for NULL, 0xD4E6 for an index past the end, else 0. */
s32 func_01EB70F0(Type1 *arg0, s32 arg1, s32 *arg2) {
    Type2 *e;
    u32 idx;

    idx = arg1 & 0xFFFF;
    *arg2 = -1;
    if (arg0 == NULL) {
        return 2;
    }
    if (idx >= arg0->f19C) {
        return 0xD4E6;
    }
    e = (Type2 *)(idx * 0x50 + (u32)arg0->f184);
    if (e->f4 != 0) {
        *arg2 = 0;
    } else if (e->f8 != 0) {
        *arg2 = 1;
    }
    return 0;
}
