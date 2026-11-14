#include "common.h"

extern void func_0015B548(s32 val);
extern s32 func_01ED5D30(s8 *arg0);

typedef struct {
    s32 f0, f4, f8, fC;
    s32 f10;
    s32 f14;
} Type1;

Type1 *D_002233A4 = 0;

// Run the query, report it, and set the state to 0x57 on success.
s32 func_L00_00779750(s8 *arg0) {
    Type1 *p = D_002233A4;
    s32 r = func_01ED5D30(arg0);
    func_0015B548(r);
    if (r != 0) {
        p->f10 = 0x57;
        if (p->f14 == 0) {
            p->f14 = 0x57;
        }
        return 0;
    }
    return 1;
}
