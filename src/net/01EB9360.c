/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EB9880(void *, s32 *, u16 *);
extern s32 func_01EB9918(char *p);
extern void func_01EBB8E0(void *, void *);
extern s32 func_01EBCF88(void *o, void *a1);
extern void func_01EBD390(void *arg0, void *arg1);
extern s32 func_01EBDDE8(s32 o, void *c, s32 which, u32 a3);
extern s32 func_01EBDEF0(void *arg0, u16 *arg1);
extern void func_01EBE608(s32 *a0, s32 a1);
extern void func_01EBF0A0(s32, void *);
extern void func_01EBF100(s32, void *);

typedef struct {
    s32 f0;
    char pad4[0x180];
    char *f184;
    char pad188[0x40];
    s32 f1C8;
    char pad1CC[4];
    u32 f1D0;
    u32 f1D4;
} Type1;

typedef struct {
    s32 f0;
    void *f4;
    char pad8[0x1C];
    u16 f24[8];
    s16 f34;
    char pad36[0x1A];
} Type2;

/* Handles a message by registering the sender in the object's table of 0x50-byte entries. */
void func_01EB9360(Type1 *arg0, void *arg1)
{
    s32 state = 0;
    s32 idx = 0xFFFE;
    u16 id = idx;
    Type2 *e;

    func_01EB9880(arg0, &state, &id);
    if (state == 9) {
        if (arg0->f1C8 == 0) {
            func_01EBB8E0(arg0, arg1);
            return;
        }
        idx = func_01EB9918((char *)arg0);
        if (idx != 0xFFFE) {
            e = (Type2 *)(arg0->f184 + idx * 0x50);
            func_01EBD390(arg0, e);
            e->f4 = arg1;
            e->f0 = 2;
            func_01EBDEF0(arg1, e->f24);
            e->f34 = 0;
            func_01EBCF88(arg0, arg1);
            func_01EBE608((s32 *)arg1, idx);
            func_01EBF0A0(arg0->f0, arg1);
            func_01EBDDE8(arg0->f0, arg1, 0, arg0->f1D0);
            func_01EBDDE8(arg0->f0, arg1, 1, arg0->f1D4);
            return;
        }
        func_01EBF100(arg0->f0, arg1);
        return;
    }
    func_01EBB8E0(arg0, arg1);
}
