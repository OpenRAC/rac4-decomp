/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct { u64 v; } __attribute__((packed)) U64P;
extern s32 func_01EA7538();
extern void func_01EED528(s32 arg0);
extern void *func_01F07FE4(void);
extern s32 func_01F081E4();
extern s32 D_0016E554[];
extern s32 D_21D9B4[];

/* Copy eight bytes into the packet and send it when the state allows. */
s32 func_01EF5128(u8 *arg0, s32 **arg1)
{
    u8 *p = (u8 *)*arg1;

    if (func_01EA7538() == 0) {
        if (D_21D9B4[0] == 1) {
            if (D_0016E554[0] == 0) {
                p += 8;
                *(U64P *)p = *(U64P *)((u8 *)D_0016E554 - 0x84);
                func_01F081E4(func_01F07FE4(), arg0 + 0x38, p);
                return 1;
            }
            func_01EED528(0x24);
        }
    }
    return 0;
}
