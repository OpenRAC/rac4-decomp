#include "common.h"

typedef s32 (*Fn438488)(s32, s32, void *);
typedef struct { s16 v[24]; } Ent_00438670;
extern Ent_00438670 D_0028C520[];
extern s32 D_00222E64;
extern u8 *D_00222E14;
extern s32 D_0028C0E0[];

/* PAL: from rac3-decomp's func_L01_0043B750 */
s32 func_L01_0058CB38(s32 idx, u8 *obj) {
    Ent_00438670 **slot;
    Ent_00438670 *e;
    Ent_00438670 *n;
    s32 i;
    slot = (Ent_00438670 **)((u8 *)((Ent_00438670 * *)&D_0028C0E0) + idx * 4);
    if (*slot == 0) {
        n = (Ent_00438670 *)((u8 *)D_0028C520 + (idx - D_00222E64) * 48);
        *slot = n;
        n->v[0] = ((obj - D_00222E14) >> 8) | 0x8000;
        obj[33] = idx;
        return 1;
    }
    e = (Ent_00438670 *)((u8 *)D_0028C520 + (idx - D_00222E64) * 48);
    for (i = 0; i < 23; i++) {
        if (e->v[i] & 0x8000) {
            e->v[i] &= 0x7FFF;
            i++;
            *(s16 *)((u8 *)e + i * 2) = ((obj - D_00222E14) >> 8) | 0x8000;
            obj[33] = idx;
            return 1;
        }
    }
    return 0;
}
