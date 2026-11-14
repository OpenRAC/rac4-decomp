#include "common.h"

typedef struct Type1 {
    s32 f0[6];
    s32 f18;
    s32 f1C;
    s32 f20[12];
} Type1;
extern Type1 D_0032FFA8[];

// Set the word at 0x18 to arg1 and clear the word at 0x1C of entry arg0 (0x50 bytes each) in D_0032FFA8.
void func_L01_005E6C68(s32 arg0, s32 arg1) {
    D_0032FFA8[arg0].f18 = arg1;
    D_0032FFA8[arg0].f1C = 0;
}
