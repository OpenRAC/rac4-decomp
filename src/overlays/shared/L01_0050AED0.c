#include "common.h"

typedef struct { s32 a[4]; } Type9;
extern Type9 D_00222758[];
extern void func_L01_0050AF48(void *arg0, s32 arg1, s32 arg2, s32 arg3);

// Picks an entry of a local copy of the D_00222758 table by arg1 (or field 0x69 when arg1 is -1) and passes it to func_L01_0050AF48.
void func_L01_0050AED0(u8 *obj, s32 arg1) {
    Type9 t;
    u32 i;
    u32 v;
    v = obj[0x69];
    if (arg1 != -1)
        v = arg1;
    t = D_00222758[0];
    i = v - 1;
    if (i < 4)
        func_L01_0050AF48(obj, t.a[i], arg1, 0);
}
