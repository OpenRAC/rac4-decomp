#include "common.h"

typedef struct Ent Ent;
typedef struct EntVt EntVt;
struct EntVt {
    char _p0[0x144];
    s32 (*f144)(Ent *, EntVt *);
};
struct Ent {
    char _p0[0x58];
    EntVt *f58;
};

extern s32 func_L00_005C9F50(s32);
extern s32 func_L00_00719A28(u8 *owner, u8 *menu, s32 text, s32 a3, s32 t0, s32 t1, s32 t2, f32 f);
extern u8 D_00220A78[];
extern u8 *D_00220D14;

s32 func_L00_0070B400(s32 arg0) {
    s32 ret;
    u8 *owner;
    u8 *e;
    u8 *o;
    Ent *ent;
    s32 r;

    ret = 1;
    owner = D_00220D14;
    if (arg0 == 2) {
        o = *(u8 **)(owner + 0x108);
        e = NULL;
        if (o != NULL) {
            e = (*(u8 *)(o + 0xA8) ^ 1) ? NULL : o;
        }
        if (e == NULL) {
            ret = 2;
            func_L00_00719A28(owner, D_00220A78, func_L00_005C9F50(0x1732), 4, 0, 0, 0, 0.6f);
            ent = *(Ent **)(D_00220D14 + 0x108);
            r = ent->f58->f144(ent, ent->f58);
            if (r == 5) {
                *((u8 *)ent + 0x390) = 1;
            } else if (r == 6) {
                *((u8 *)ent + 0x274) = 1;
            } else if (r == 10) {
                *((u8 *)ent + 0x2882) = 1;
            }
        }
    }
    return ret;
}
