#include "common.h"

typedef struct Cam {
    u8 pad0[0x240];
    s32 x240;
    s32 x244;
    s32 x248;
    s32 x24C;
    s32 x250;
    s32 x254;
    s32 x258;
} Cam;

typedef struct Pk {
    u8 pad0[0x10];
    u64 x10;
    u8 pad18[8];
    u64 x20;
} Pk;

extern u32 *D_00222FE0;
extern Cam D_0023C740;
extern u8 D_00171630[];
extern u8 D_00171570[];
extern Pk D_00171600;

extern void func_00453F30(void *d, void *s, s32 n);
extern void func_004E88B8(s32 a, u64 b, s32 c);

// Writes three DMA tags to the packet at D_00222FE0, fills two qwords of D_00171600 from D_0023C740 and copies 0x30 bytes to the packet.
void func_00448DC8(void) {
    Cam *c;
    Pk *p;
    u64 w;

    D_00222FE0[0] = 0x30000013;
    D_00222FE0[1] = (u32)D_00171630;
    D_00222FE0[2] = 0;
    D_00222FE0[3] = 0x50000013;
    D_00222FE0 += 4;
    D_00222FE0[0] = 0x30000009;
    D_00222FE0[1] = (u32)D_00171570;
    D_00222FE0[2] = 0;
    D_00222FE0[3] = 0x50000009;
    D_00222FE0 += 4;
    D_00222FE0[0] = 0x10000003;
    D_00222FE0[1] = 0;
    D_00222FE0[2] = 0;
    D_00222FE0[3] = 0x50000003;
    c = &D_0023C740;
    p = &D_00171600;
    p->x10 = (u64)c->x240 | ((u64)c->x244 << 16) | ((u64)c->x248 << 32) | ((u64)c->x24C << 48);
    D_00222FE0 += 4;
    p->x20 = (u64)c->x240 | ((u64)c->x244 << 16) | ((u64)c->x248 << 32) | ((u64)c->x24C << 48);
    func_00453F30(D_00222FE0, p, 0x30);
    D_00222FE0 += 0xC;
    func_004E88B8(0x3D, (u64)c->x250 | ((u64)c->x254 << 8) | ((u64)c->x258 << 16), 0);
    func_004E88B8(0x51, 0, 0);
}
