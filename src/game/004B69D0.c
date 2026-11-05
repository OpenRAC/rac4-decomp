#include "common.h"

typedef struct {
    u8 pad0[0x10];
    u32 f10;
    u8 pad14[0x1E4];
} Type2;

extern Type2 D_3098F0[];

// Clears the 0x10 field of record ARG0 of the 0x1F8-byte table at D_3098F0.
void func_004B69D0(u32 arg0) {
    D_3098F0[arg0].f10 = 0;
}
