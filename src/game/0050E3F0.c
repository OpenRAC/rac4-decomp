#include "common.h"

typedef struct { u8 pad[0x54]; u8 flags; } Obj;

/* Sets (on) or clears the bits of mask in the flag byte at +0x54. */
void func_0050E3F0(Obj *o, u8 mask, s32 on) {
    if (on != 0) {
        o->flags |= mask;
    } else {
        o->flags &= ~mask;
    }
}
