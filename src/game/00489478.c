#include "common.h"

typedef struct {
    u8 pad0[0x50];
    u16 f50;
    u8 pad52[0x26];
    u16 f78;
    u8 pad7A[0x4E];
    u16 fC8;
} Type1;

extern Type1 D_206948;

// Loads the 0x4 marker into three u16 fields of D_206948. The stores are written
// in the order the compiler emits them from (it emits the last one first).
void func_00489478(void) {
    D_206948.f50 = 4;
    D_206948.fC8 = 4;
    D_206948.f78 = 4;
}
