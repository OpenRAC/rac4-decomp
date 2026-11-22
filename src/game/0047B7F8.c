#include "common.h"
typedef struct { s32 f0, f4, f8, pad[4]; } E;
extern E D_003D7D88[];
extern s32 D_0021EDD4;
extern s32 func_0045E038(s32);
extern s32 func_00496C90(s32, s32);
extern u8 *func_00510C18(s32);

s32 func_0047B7F8(s32 a0, s32 a1, s32 a2) {
    E *e = &D_003D7D88[a0];
    s32 i;
    u8 *p;
    s32 t;
    s32 st = 2;
    if (e->f0 == a1) {
        if (e->f4 == a2) {
            if (a2 != 0) {
                p = func_00510C18(a0);
                if (p != 0 && p[0x266D] != 0) {
                    t = (*(s32 (**)(u8 *))(*(u8 **)(p + 0x14) + 0x4C))(p);
                    func_00496C90(t, func_0045E038(a2));
                }
            }
            e->f8 = st;
            e->f4 = a2;
            return 2;
        }
    }
    if (D_0021EDD4 == 0) {
        for (i = 0; i < 10; ) {
            if (i != a0 && D_003D7D88[i].f0 != 0) return 0;
            i++;
        }
    }
    if (e->f0 == 0) {
        if (a2 != 0) {
            p = func_00510C18(a0);
            if (p != 0 && p[0x266D] != 0) {
                t = (*(s32 (**)(u8 *))(*(u8 **)(p + 0x14) + 0x4C))(p);
                func_00496C90(t, func_0045E038(a2));
            }
        }
        e->f8 = st;
        e->f0 = a1;
        e->f4 = a2;
        return 1;
    }
    return 0;
}
