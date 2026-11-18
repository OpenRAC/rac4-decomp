#include "common.h"

typedef struct Type1 {
    s32 f0[3];
    s32 f0C;
    s32 f10;
    s32 f14[41];
} Type1;
extern Type1 D_00330248[];

// Set the word at 0x0C to arg1 and clear the word at 0x10 of entry arg0 (0xB8 bytes each) in D_00330248.
void func_L01_005EFDE0(s32 arg0, s32 arg1) {
    D_00330248[arg0].f0C = arg1;
    D_00330248[arg0].f10 = 0;
}
