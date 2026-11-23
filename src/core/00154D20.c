/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_00126BC0(s32);
extern void func_00126BE0(s32);

typedef struct {
    u8 pad0[0x14];
    s32 f14;
    u8 pad1[4];
    s32 f1c;
    u8 pad2[0xF0];
} Type1;

typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad1[0x10];
    s32 f40;
    u8 pad2[0x14];
    s32 f58;
    u8 pad3[0x2C];
    Type1 f88[1];
} Type2;

extern Type2 D_1BCC28;

s32 func_00154D20(s32 arg0) {
    s32 idx = arg0 - 1;
    Type1 *e;

    if ((D_1BCC28.f40 < idx) || (idx < 0)) {
        return 0x80000004;
    }
    e = (Type1 *)((u8 *)&D_1BCC28 + (((idx << 4) + idx) << 4) + 0x88);
    func_00126BE0(D_1BCC28.f2C);
    if ((e->f14 != 0) && (e->f14 == arg0)) {
        D_1BCC28.f58 = D_1BCC28.f58 - 1;
        e->f14 = 0;
    }
    if (e->f1c == 4) {
        e->f1c = 1;
    }
    func_00126BC0(D_1BCC28.f2C);
    return 0;
}
