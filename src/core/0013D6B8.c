/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    char pad8[0x20];
    void (*fa[4])(void *);
    void (*fb[4])(void *);
    char a[4][0x1C];
    char b[4][0x1C];
    s32 unk128;
    s32 count;
    s32 unk130;
    s32 pad134;
    s32 unk138;
    s32 unk13C;
} Elem_13D6B8;
typedef struct {
    char pad0[0x5A0];
    Elem_13D6B8 e[2];
    char pad820[0x10];
    s32 unk830;
} Dec_13D6B8;

extern char D_00195230[];
extern void func_00146638(void *, void *);
extern void func_0013F1C8(s32, s32);
extern void func_0013F0D8(s32, s32, s32);

/* from rac2-decomp's func_0012A1C8 */
void func_0013D6B8(Dec_13D6B8 *p, s32 idx) {
    s32 i;
    if (p->e[idx].unk138 != 0) {
        for (i = 0; i < p->e[idx].count; i++) {
            p->e[idx].fa[i](p->e[idx].a[i]);
            p->e[idx].fb[i](p->e[idx].b[i]);
        }
    }
    if (p->e[idx].unk130 != 0 && p->e[idx].unk13C != 0) {
        func_00146638(p, D_00195230);
    }
    if (p->e[idx].unk130 != 0) {
        func_0013F1C8(p->e[idx].unk128, p->e[idx].unk4);
    } else if (p->e[idx].unk13C != 0) {
        func_0013F1C8(p->e[idx].unk128, p->unk830);
    } else {
        func_0013F0D8(p->e[idx].unk128, p->unk830, p->e[idx].unk4);
    }
}
