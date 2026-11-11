#include "common.h"

typedef struct {
    u8 b0, b1, b2, b3;
    s16 s4, s6, s8, s10, s12;
    u8 e, f;
} Rec_003F2058;
typedef struct {
    u8 pad[0x54C];
    u8 b54C;
    u8 pad54D[0x558 - 0x54D];
    u8 b558;
} Ctx_003F2058;
typedef struct {
    Rec_003F2058 r[8];
} Tab_003F2058;
int func_00438D38();
extern Tab_003F2058 D_003D6458[];

/* from rac3-decomp's func_L01_003F2058 */
int func_00438D38(Rec_003F2058 *src, Ctx_003F2058 *ctx)
{
    int base = 0;
    int n = 0;
    int i;
    int j;
    if (ctx) {
        if (ctx->b558 == 255)
            return 0;
        base = ctx->b54C * 4 + ctx->b558;
    }
    for (n = 0; n < 8 && src[n].b0 != 255; n++)
        ;
    j = 0;
    for (i = 0; i < 8 && j < n; i++) {
        if (D_003D6458[base].r[i].b0 == 0)
            j++;
    }
    if (j != n)
        return -1;
    for (j = 0; j < n; j++) {
        for (i = 0; i < 8 && D_003D6458[base].r[i].b0 != 0; i++)
            ;
        if (i < 8) {
            D_003D6458[base].r[i].b0 = src[j].b0;
            D_003D6458[base].r[i].b1 = src[j].b1;
            D_003D6458[base].r[i].b2 = src[j].b2;
            D_003D6458[base].r[i].b3 = src[j].b3;
            D_003D6458[base].r[i].s4 = src[j].s4;
            D_003D6458[base].r[i].s6 = src[j].s6;
            D_003D6458[base].r[i].s8 = src[j].s8;
            D_003D6458[base].r[i].s10 = src[j].s10;
            D_003D6458[base].r[i].s12 = src[j].s12;
            D_003D6458[base].r[i].e = src[j].e - src[j].f;
            D_003D6458[base].r[i].f = src[j].f;
            if (D_003D6458[base].r[i].s10 + D_003D6458[base].r[i].s12 == 0)
                D_003D6458[base].r[i].s10++;
        }
    }
    return i;
}
