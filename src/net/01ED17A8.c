/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    u16 unk0;
    u16 pad2;
    u32 unk4;
} Slot;

typedef struct {
    u32 unk0;
    u8 pad[0x88];
    u16 *unk8C;
} Ctx;

extern Ctx *func_01ED2458(s32);

s32 func_01ED17A8(s32 arg0, s32 arg1, s32 arg2, Slot *arg3) {
    Ctx *c;
    u32 idx;

    if (arg0 == 0)
        return -1;
    if (arg3 == 0)
        return -1;
    c = func_01ED2458(arg0);
    if (c == 0)
        return -1;
    idx = arg3->unk4;
    if (idx >= c->unk0)
        return -1;
    c->unk8C[idx] = arg3->unk0;
    return 8;
}
