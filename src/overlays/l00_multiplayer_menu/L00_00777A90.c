#include "common.h"
/* Ported from rac3-decomp's func_L39_006DA958 (src/levels/39_multiplayer_menu/L39_006D8E90.c, GPL-3.0), the same code in both games. */

extern long func_0012E370(void);
extern long func_0012FEB0(long, long);
typedef struct {
    s32 f0;
    u8 pad4[0x158];
    u8 f15C, f15D;
    u8 pad15E[2];
    s32 f160;
    u8 pad164[4];
    u8 f168;
    u8 pad169[3];
    s32 f16C;
    u8 pad170[0x28];
    u8 f198, f199;
    u8 pad19A[2];
    s32 f19C;
    u8 pad1A0[4];
    u8 f1A4;
    u8 pad1A5[3];
    s32 f1A8;
} Type1;
s32 func_L00_00777C50(Type1 *);
s32 func_L00_007780F8();
s32 func_L00_00777A90(Type1 *p) {
    s32 r = 1;
    if (p->f15C) {
        if (p->f15D == 0) {
            if (p->f168 && p->f0 >= 0) {
                s32 t = func_0012FEB0(func_0012E370(), 0x24000);
                s32 ok = 1;
                if (p->f160 >= 0 && t - p->f160 < p->f16C) {
                    ok = 0;
                }
                if (ok) {
                    r = func_L00_00777C50(p);
                }
            }
        } else if (p->f0 >= 0) {
            if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - p->f160 > 15000) {
                p->f15D = 0;
                func_L00_00777C50(p);
                r = 0;
            }
        }
    }
    if (p->f198) {
        if (p->f199 == 0) {
            if (p->f1A4) {
                s32 t = func_0012FEB0(func_0012E370(), 0x24000);
                s32 ok = 1;
                if (p->f19C >= 0) {
                    if (t - p->f19C < p->f1A8) {
                        ok = 0;
                    }
                }
                if (ok) {
                    r = func_L00_007780F8(p);
                }
            }
        } else {
            if ((s32)func_0012FEB0(func_0012E370(), 0x24000) - p->f19C > 15000) {
                p->f199 = 0;
                func_L00_007780F8(p);
                r = 0;
            }
        }
    }
    return r;
}
