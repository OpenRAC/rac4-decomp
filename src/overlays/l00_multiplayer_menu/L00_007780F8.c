#include "common.h"

typedef struct { char pad[0x10]; s32 f10; s32 f14; } Global;
typedef struct {
    char pad0[0x199];
    u8 f199;
    char pad19A[0x19C - 0x19A];
    s32 f19C;
    char pad1A0[0x1B0 - 0x1A0];
    u16 f1B0;
} Obj;

extern u64 func_0012E370(void);
extern s64 func_0012FEB0(s64, s64);
extern s32 func_01ED8000();
void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern u16 D_00221880[];
extern char D_0015D3F8[];
Global *D_002233A4 = 0;

s32 func_L00_007780F8(Obj *p) {
    u16 local[16];
    s32 ret = 1;
    Global *g;

    g = D_002233A4;
    if (p->f199 == 0) {
        local[0] = D_00221880[0];
        local[11] = 1;
        local[12] = p->f1B0;
        p->f199 = 1;
        p->f19C = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B548(func_01ED8000(local, D_0015D3F8, 0));
        if (func_0015B558() != 0) {
            g->f10 = 0x52;
            if (g->f14 == 0) {
                g->f14 = 0x52;
            }
            ret = 0;
        }
    }
    return ret;
}
