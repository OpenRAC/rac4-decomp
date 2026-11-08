/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    char _p4[0xC];
    s32 f10;
};

s32 func_01EA74A0();
s32 func_01EA76E8(s32);
s32 func_01EA95C0(void *);
s32 func_01EC26C8(s32);

s32 func_01EC21C8(Type1 *arg0) {
    s32 temp_v1;

    func_01EA76E8(arg0->f0);
    func_01EA95C0((void *)((u8 *)arg0 + 0x58));
    func_01EA95C0((void *)((u8 *)arg0 + 0x5C));
    temp_v1 = arg0->f10;
    if (temp_v1 != 0) {
        func_01EC26C8(temp_v1);
        arg0->f10 = 0;
    }
    func_01EA74A0();
    return 0;
}
