/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x5B10];
    s32 f5B10;
};

s32 func_01EEE12C();
void func_01EEEDC4(s32);
void func_01F0C090(void *, s32);
extern s32 D_0019DBB8[];

void func_01F002FC(s32 arg0, Type1 *arg1) {
    s32 temp_v0;

    if (arg1 == NULL) {
        func_01F0C090(D_0019DBB8, 0x36);
    }
    if (arg1->f5B10 == 0) {
        temp_v0 = func_01EEE12C();
        if (temp_v0 == 0) {
            func_01F0C090(D_0019DBB8, 0x3B);
        }
        func_01EEEDC4(temp_v0);
    }
}
