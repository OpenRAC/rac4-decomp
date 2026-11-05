#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u32 fC;
    u8 pad10[0x1E8];
} Type2;

extern Type2 D_3098F0[];

// Clears the 0xC field of record ARG0 of the 0x1F8-byte table at D_3098F0.
void func_004B69B0(u32 arg0) {
    D_3098F0[arg0].fC = 0;
}
