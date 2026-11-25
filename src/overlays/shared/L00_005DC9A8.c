#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 func_L00_00696108(void *a0, s32 a1, s32 a2, s32 a3);
extern s32 D_00223120;
extern char D_00247C80[];

typedef struct {
    u128 a;
    u128 b;
} Entry;

typedef struct {
    Entry e[8];
    s32 unk100;
    s32 unk104;
} Rec;

void func_L00_005DC9A8(char *arg0)
{
    Rec *r = (Rec *)(*(s32 *)(arg0 + 0x2F10) * 0x110 + D_00247C80);
    Entry *e = r->e;
    s32 i;

    i = func_L00_00696108(&D_00223120, r->unk100 + 1, 0, 7);
    r->unk100 = i;
    e[i].a = *(u128 *)(arg0 + 0xA0);
    e[r->unk100].b = *(u128 *)(arg0 + 0xB0);
    if (r->unk104 < 8) {
        r->unk104 = r->unk104 + 1;
    }
}
