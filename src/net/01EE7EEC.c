/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void *func_01F07100(void);
extern s32 func_01F07554(void *arg0, void *arg1);

typedef struct Blk { u8 b[0x80]; } Blk;

// Copies a 0x80-byte block from arg1+0x100 to arg0+0x3A56, then stores the halfword at arg1+0x380 into arg0+0x3A54; returns 1.
s32 func_01EE7EEC(u8 *arg0, u8 *arg1) {
    func_01F07554(func_01F07100(), arg1);
    *(Blk *)(arg0 + 0x3A56) = *(Blk *)(arg1 + 0x100);
    *(u16 *)(arg0 + 0x3A54) = *(u16 *)(arg1 + 0x380);
    return 1;
}
