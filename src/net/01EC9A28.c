/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 f0; char _p1[0x43]; } Ent;
typedef struct { char _p0[0x10C]; u32 f10C; } Ctx;
typedef struct { char _p0[0x130]; Ent *f130; } Tab;
extern Ctx *D_00167F38;
extern Tab D_001B7258;
extern Ent *func_01EA0668(u32);
Ent *func_01EC9A28(u32 i) {
    if (i < D_00167F38->f10C) {
        if (D_001B7258.f130 == 0) {
            u32 j;
            D_001B7258.f130 = func_01EA0668(D_00167F38->f10C * sizeof(Ent));
            if (D_001B7258.f130 == 0) {
                return 0;
            }
            for (j = 0; j < D_00167F38->f10C; j++) {
                D_001B7258.f130[j].f0 = 0;
            }
        }
        return &D_001B7258.f130[i];
    }
    return 0;
}
