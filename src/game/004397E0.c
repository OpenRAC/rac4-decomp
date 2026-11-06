#include "common.h"

typedef struct {
    u32 a : 8;
    u32 b : 4;
    u32 c : 16;
    u32 d : 4;
} Bits;

/* Through a pointer passed as a 64-bit integer: sets the 16-bit field at bit 12 and the 4-bit field at bit 28 to all ones, and clears the low byte. */
void func_004397E0(s32 unused, s64 where) {
    Bits *p = (Bits *)where;
    p->c = 0xFFFF;
    p->d = 0xF;
    p->a = 0;
}
