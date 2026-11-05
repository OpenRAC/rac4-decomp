#include "common.h"

typedef struct {
    u8 pad0[0x50];
    s16 f50;
    s16 f52;
    u8 pad54[0x74];
    s16 fC8;
    s16 fCA;
} Type1;

extern Type1 D_206948;

// Loads -0x8000 into two s16 fields of D_206948 and clears the s16 next to each.
// The stores are written in the order the compiler emits them from.
void func_00489458(void) {
    D_206948.f50 = -0x8000;
    D_206948.f52 = 0;
    D_206948.fC8 = -0x8000;
    D_206948.fCA = 0;
}
