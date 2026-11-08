#include "common.h"

extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_L00_00666DF0(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { s16 h0; s16 h2; } S_98T;
extern s32 D_0032A3E0[];
extern u8 *D_00329960[];
extern S_98T D_00329EE0[];

/* from rac3-decomp's func_003DEE20 */
void func_L00_00666DF0(void) {
    s32 *ip = D_0032A3E0;
    u8 *obj;
    u8 *sub;
    u8 *e;
    u8 *q; u8 *tab;
    s32 j, k, off;
    S_98T *t;
    while (*ip >= 0) {
        obj = D_00329960[*ip];
        j = 0;
        if (*(s16 *)(obj + 0x28) > 0) {
            tab = obj + 0x40;
            do {
                off = j * 8;
                sub = *(u8 **)(tab + off);
                e = sub + 0x10;
                q = e + *(s32 *)(e + 4) * 16 + 0x10;
                for (k = 0; k < *(s32 *)e; k++, q += 0x40) {
                    t = &D_00329EE0[q[0x13]];
                    if (t->h0 != 0) *(u32 *)(q + 0x30) = (*(u32 *)(q + 0x30) & 0xFFFFC000) | t->h0;
                    if (t->h2 != 0) *(u32 *)(q + 0x20) = (*(u32 *)(q + 0x20) & 0xFFFFC000) | t->h2;
                }
                j++;
            } while (j < *(s16 *)(obj + 0x28));
        }
        ip++;
    }
}
