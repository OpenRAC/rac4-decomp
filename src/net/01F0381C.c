/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x1B8];
    s32 f1B8;
};

s32 func_0011A518(s32, s32, s32);
s32 func_01EEDCD0(s32, void *, s32);
extern s32 D_0019DF60[];

void func_01F0381C(Type1 *arg0) {
    func_01EEDCD0((void *)((u8 *)arg0 + 0x38), D_0019DF60, 0x40);
    func_0011A518((void *)((u8 *)arg0 + 0xB4), 0, 0x100);
    arg0->f1B8 = 0;
}
