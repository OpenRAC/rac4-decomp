#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Type1;
extern Type1 D_375CD0[];

// Clear entry arg0 of a 12-byte-entry table.
void func_L41_0040DC70(s32 arg0) {
    *(u8 *)&D_375CD0[arg0] = 0;
    D_375CD0[arg0].f4 = 0;
    D_375CD0[arg0].f8 = 0;
}
