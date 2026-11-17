#include "common.h"

extern s32 func_0070C410(s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
} Entry;

extern Entry D_004B7210[];
extern u8 D_003F3F78[];

void func_L00_0070CD80(s32 arg0, s32 arg1) {
    s32 t = func_0070C410(arg1);
    s32 o12 = t * 0xC;
    s32 flag;
    s32 idx;
    s32 *p;
    s32 v;

    arg0 += o12;
    flag = D_004B7210[t].unkC;
    ((u8 *)arg0)[0x118] = 0;
    if (flag != 0) {
        u8 *base = D_003F3F78;
        u8 *b8 = base + 8;
        idx = D_004B7210[t].unk4 * 0x14;
        p = (s32 *)(b8 + idx);
        v = *p & ~D_004B7210[t].unk8;
        *p = v;
        if (v == 0) {
            base[idx] = 0;
        }
    }
}
