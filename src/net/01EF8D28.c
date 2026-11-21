/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011AB04(u8 *);
extern s32 func_01EE3A18(void *arg0, const u8 *arg1);
extern void *func_01EEDCD0(void *, const void *, s32);
extern s32 func_01EF308C(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_01EF339C(s32 a, void *b, void *out);
extern void func_01EF382C(void *);
extern void func_01EF8CB4(u8 *p);
extern void func_01F06988(s8 *arg0);
extern void func_01F0C090(char *arg0, s32 arg1);
extern u8 D_001704B0[];
extern u8 D_0019D1C8[];
extern u8 D_0019D1D0[];
extern u8 D_0019D1D8[];
extern u8 D_0019D1E0[];
extern u8 D_0019D1E8[];
extern u8 D_0019D1F0[];
extern u8 D_0019D1F8[];
extern char D_0019D208[];

typedef struct { u8 b[0x80]; } B80;
typedef struct {
    s32 f0;
    u8 pad4[0xC];
    s32 f10;
    u8 pad14[0x9C];
    u8 *fB0;
    B80 blk;
    u8 pad134[0x28];
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
} R;

/* Sets up a record: resolves its tables, copies a 0x80-byte block in, then looks up its flags. */
void func_01EF8D28(R *a, s32 arg1)
{
    s32 sp0;
    B80 *sp4;
    s32 r;

    func_01EF382C(a);
    a->fB0 = D_001704B0;
    func_01EF8CB4((u8 *)a);
    func_01EF308C(arg1, (s32)D_0019D1C8, &sp0);
    func_01EF308C(arg1, (s32)D_0019D1D0, &a->f15C);
    func_01EF308C(arg1, (s32)D_0019D1D8, &a->f160);
    func_01EF308C(arg1, (s32)D_0019D1E0, &a->f164);
    func_01EF308C(arg1, (s32)D_0019D1E8, &a->f168);
    func_01EF339C(arg1, D_0019D1F0, &sp4);
    r = func_01EE3A18((void *)a->f0, D_0019D1F8);
    if (r == 0) {
        func_01F0C090(D_0019D208, 0x3D);
    }
    func_01EEDCD0((u8 *)a + 0x134, (void *)r, 0x20);
    a->blk = *sp4;
    if (func_0011AB04((u8 *)a + 0x134) == 0) {
        func_01F0C090(D_0019D208, 0x41);
    }
    a->f16C = sp0;
    if (&a->blk != 0 && func_0011AB04((u8 *)&a->blk) != 0) {
        a->f10 = 1;
        func_01F06988((s8 *)&a->blk);
        return;
    }
    a->f10 = 0;
}
