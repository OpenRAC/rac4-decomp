/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x40];
    s32 f40;
    char _p44[0x100];
    s32 f144;
};

s32 func_0011A518(void *, s32, s32);

void func_01EEDA60(Type1 *arg0) {
    arg0->f40 = -1;
    arg0->f144 = 0;
    func_0011A518((void *)((u8 *)arg0 + 0x44), 0, 0x100);
    func_0011A518(arg0, 0, 0x40);
}
