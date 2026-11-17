#include "common.h"

extern void func_0011A9EC(void *, void *);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED70C8();
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern u16 D_00221880[];
extern u8 *D_002233A4;

typedef struct {
    u16 f0;
    char f2[0x13];
    char f15[0x13];
    s32 f28;
    s32 f2C;
    char f30[0x40];
} Locals;

/* Sends a request and returns whether it failed. */
s32 func_L00_007771D8(s32 a0, s32 a1) {
    Locals l;
    s32 r = 1;
    u8 *obj = D_002233A4;
    void *v = *(void **)(obj + 0x64);
    l.f0 = D_00221880[0];
    func_0011A9EC(l.f15, v);
    l.f2C = -1;
    l.f28 = 0;
    func_L00_005C1758(l.f30, a1, 0x40);
    func_0015B548(func_01ED70C8(&l));
    if (func_0015B558() != 0) {
        *(s32 *)(obj + 0x10) = 0x53;
        if (*(s32 *)(obj + 0x14) == 0) {
            *(s32 *)(obj + 0x14) = 0x53;
        }
        r = 0;
    }
    return r;
}
