#include "common.h"

typedef struct Ent {
    u8 pad0[0x10];
    u8 *x10;
    s16 x14;
    s16 x16;
    s16 x18;
    s16 x1A;
    s16 x1C;
    u8 pad1E[2];
} Ent;

typedef struct Hdr {
    s16 n;
    u8 pad2[0xE];
    Ent e[1];
} Hdr;

typedef struct Dat {
    s32 x0;
} Dat;

extern u32 *D_00222FE0;
extern u8 D_00171760[];
typedef struct B { s32 x0; s32 x4; s32 x8; } B;
extern B D_001DFD70[];

extern void func_004FF510(void);
extern void func_004FF548(void);
extern void func_004E0D38(Ent *e, s32 n, u8 *flags);
extern void func_004E07A8(void);
extern s32 func_004E0850(u8 *a, void *b, s32 c);
extern void func_004E0948(s32 a, u8 *b, u8 *c, void *d);
extern void func_004E88B8(s32 a, u64 b, s32 c);

// Walks h->n entries of 0x20 bytes, using a byte per entry in the scratchpad at 0x70003F00, then calls func_004E88B8 twice.
void func_004E0218(Hdr *h) {
    Ent *e;
    u8 *flags;
    u8 *a;
    u8 *b;
    u8 *c;
    s32 i;

    if (h->n == 0) {
        return;
    }
    func_004FF510();
    func_004E0D38(h->e, h->n, (u8 *)0x70003F00);
    func_004E07A8();
    e = h->e;
    flags = (u8 *)0x70003F00;
    D_00222FE0[0] = 0x30000007;
    D_00222FE0[1] = (u32)D_00171760;
    D_00222FE0[2] = 0;
    D_00222FE0[3] = 0x50000007;
    D_00222FE0 += 4;
    for (i = 0; i < *(s16 *)h; i++, e++, flags++) {
        if (*flags == 0) {
            b = e->x10 + e->x1C;
            a = e->x10 + e->x18;
            c = e->x10 + e->x1A;
            if (func_004E0850(a, (void *)0x70000000, e->x14) == 0) {
                func_004E0948(h->e[i].x16, b, c, (void *)0x70000000);
            }
        }
    }
    func_004FF548();
    func_004E88B8(0x47, 0x3180B, 0);
    func_004E88B8(0x4E, (u64)(D_001DFD70[0].x8 >> 13) | 0x1000000 | ((u64)0x8000 << 17), 0);
}
