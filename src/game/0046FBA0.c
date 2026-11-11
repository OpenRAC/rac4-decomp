#include "common.h"
typedef struct {
    short f0, f2;
    unsigned char f4, f5;
    char pad[2];
} Entry;
typedef struct {
    s32 f0;
    f32 f4;
    char pad8[6];
    s16 fE;
    char pad10[5];
    u8 f15;
} Obj;
typedef struct {
    char pad0[8];
    u8 f8;
    char pad9[15];
    s32 f18;
} Req;
extern Entry D_0026AFC0[];
extern char D_00266FC0[];
extern int D_00221474, D_00221470;
void func_004697C0(s32, s32, s32);
void func_00469800(void);
void func_0046DAF8(s32);
void func_0046E810(void *, s32);
void func_0046E9E8(s32, f32);

void func_0046FBA0(Obj *a0, Req *a1)
{
    s32 freeIdx = D_00221474;
    s32 size = a1->f8;
    s32 i;
    Entry *e;
    Entry *n;

    if (freeIdx == 255) return;
    for (i = D_00221470; i != 255; i = e->f5) {
        e = &D_0026AFC0[i];
        if (e->f4 == 0 && e->f2 >= size) break;
    }
    if (i == 255) return;
    if (size < e->f2) {
        n = &D_0026AFC0[freeIdx];
        D_00221474 = n->f5;
        n->f5 = e->f5;
        e->f5 = freeIdx;
        n->f4 = 0;
        n->f0 = e->f0 + size;
        n->f2 = e->f2 - size;
    }
    e->f2 = size;
    e->f4 = 1;
    func_004697C0(a1->f18, size, 0x2000);
    func_00469800();
    func_0046DAF8(size);
    func_0046E9E8(a0->f0, a0->f4);
    func_0046E810(D_00266FC0 + e->f0 * 32, size);
    a0->fE = i;
    a0->f15 |= 4;
}
