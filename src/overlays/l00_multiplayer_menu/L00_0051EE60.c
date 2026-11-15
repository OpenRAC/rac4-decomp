/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_004FAD28(void *);
extern void func_00538B40(s32);
extern void func_L00_00538038(void *);

typedef struct Type1 {
    u8 pad0[4];
    u8 f4[0x14];
    u8 f18[0x14];
    u8 f2C[0x14];
    s32 f40;
    u8 *f44;
    u8 pad1[8];
    s32 *f50;
    s32 f54;
} Type1;

/* Frees the sub-objects owned by the body at arg0->f8, then the body; returns 0. */
s32 func_L00_0051EE60(void *arg0) {
    Type1 *b = *(Type1 **)((u8 *)arg0 + 8);
    s32 n;
    s32 i;

    if (b == 0) return 0;
    n = b->f40;
    func_L00_00538038(b->f4);
    func_L00_00538038(b->f18);
    func_L00_00538038(b->f2C);
    for (i = 0; i < n; i++) {
        func_L00_00538038(&b->f44[i * 0x3C]);
        func_L00_00538038(&b->f44[i * 0x3C + 0x14]);
        func_L00_00538038(&b->f44[i * 0x3C + 0x14 + 0x14]);
        if (b->f50[i] != 0) func_00538B40(b->f50[i]);
    }
    if (b->f44 != 0) func_004FAD28(b->f44);
    if (b->f50 != 0) func_004FAD28(b->f50);
    if (b->f54 != 0) func_00538B40(b->f54);
    func_004FAD28(b);
    return 0;
}
