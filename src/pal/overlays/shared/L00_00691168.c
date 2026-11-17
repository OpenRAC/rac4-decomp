#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct Obj {
    u8 pad0[0x62];
    s8 x62;
    u8 pad63[4];
    u8 x67;
    u16 x68;
    u8 pad6A[0x22];
    u8 x8C;
} Obj;

typedef struct Cam {
    u128 x0;
    u8 pad10[0x10];
    u8 x20[1];
} Cam;

extern Obj D_004CD750;
// Initial value from level 00; each level sharing this code holds its own pointer here.
Obj *D_002203B4 = &D_004CD750;
extern u8 *D_00222FE0;
extern Cam D_0022CAC0;
extern s32 D_00223184;
extern u8 D_00223200;
extern u8 D_00223201;
extern u8 D_00223202;
extern u8 D_00223203;
extern u8 D_00223210;

extern s32 func_0046DCE8(s32 a, s32 b);
extern void func_L00_006904A8(u128 a, u8 *b);
extern void func_L00_00690938(void);
extern void func_L00_00690C40(void);
extern void func_004F97F8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_L00_0068F6A8(u8 **p, s32 i);

// Draws two elements through func_004F97F8; the second one writes its packet at D_00222FE0 through func_L00_0068F6A8.
void func_L00_00691168(void) {
    u8 *pk;
    u8 *start;
    s32 i;
    u32 n;

    if (func_0046DCE8(0x2022, 0x50) == 0) {
        func_L00_006904A8(D_0022CAC0.x0, D_0022CAC0.x20);
        func_L00_00690938();
        func_L00_00690C40();
    }
    if (D_002203B4->x62 >= 0) {
        func_004F97F8(D_00223184, 0x100, 0x100, D_002203B4->x67 != 0, 0, D_00223203,
                      (D_00223202 << 16) | (D_00223201 << 8) | D_00223200, -1);
    }
    if (D_00223210 != 0 && D_002203B4->x68 != 0) {
        start = D_00222FE0 + 0x10;
        pk = start;
        *(u64 *)(D_00222FE0 + 0x10) = 0x1000000000000008;
        pk += 8;
        *(u64 *)pk = 0xE;
        pk += 8;
        for (i = 0; i < 2; i++) {
            func_L00_0068F6A8(&pk, i);
        }
        n = (u32)(pk - start) >> 4;
        ((u32 *)D_00222FE0)[0] = n | 0x10000000;
        ((u32 *)D_00222FE0)[1] = 0;
        ((u32 *)D_00222FE0)[2] = 0;
        ((u32 *)D_00222FE0)[3] = n | 0x50000000;
        D_00222FE0 += (n << 4) + 0x10;
        func_004F97F8(D_00223184, 0x100, 0xE0, D_002203B4->x8C != 0, 1, 0x80, 0x808080, 0xFFFF);
    }
}
