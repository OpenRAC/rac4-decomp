/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C1F40 (src/levels/39_multiplayer_menu/L39_004C1F40.c, GPL-3.0), the same code in both games. */

typedef struct B_004C1F40 {
    u8 pad0[0x10];
    u32 len;
    u8 data[1];
} B_004C1F40;
typedef struct A_004C1F40 {
    u8 pad0[0x6C];
    u32 len6C;
    u8 data70[0x90 - 0x70];
    u32 len90;
    u8 data94[0xA4 - 0x94];
    u32 total;
    u8 dataA8[1];
} A_004C1F40;
typedef struct Type1 {
    u8 pad0[0x50];
    A_004C1F40 *a;
    u8 pad54[0xB0 - 0x54];
    B_004C1F40 *b;
} Type1;
extern void *func_L00_0051A740(void);
extern s32 func_L00_0051B498(void);
extern void func_L00_00519490(void *, s32);
extern u32 func_L00_0051A6E8(void *);
extern void func_L00_00519578(void *, void *, u32);
extern void func_L00_005195A8(void *, void *, void *);
extern void func_L00_0051A7B8(void *);
typedef struct L_004C1F40 {
    u8 c;
    u32 out[3];
} L_004C1F40;
void func_L00_004FDD40(Type1 *s) {
    L_004C1F40 l;
    void *ctx;
    u32 step;
    u32 i;
    u8 *p;
    l.c = '0';
    i = 0;
    ctx = func_L00_0051A740();
    func_L00_00519490(ctx, func_L00_0051B498());
    step = func_L00_0051A6E8(ctx);
    p = s->a->dataA8;
    while (i < s->a->total) {
        func_L00_00519490(ctx, 0);
        i += step;
        func_L00_00519578(ctx, s->b->data, s->b->len);
        func_L00_00519578(ctx, &l.c, 1);
        l.c++;
        func_L00_00519578(ctx, s->a->data70, s->a->len6C);
        func_L00_00519578(ctx, s->a->data94, s->a->len90);
        func_L00_005195A8(ctx, p, l.out);
        p += step;
    }
    func_L00_0051A7B8(ctx);
}
