#include "common.h"

typedef struct Type1 {
    int f0, f4, f8;
} Type1;
extern Type1 D_00171DB8[];
extern int D_002218E0;
extern char D_0030A540[];
extern int D_003D95AC[];
extern void func_001586B8(int);
extern void func_004985F0(int);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, const char *);
/* Toggle the selected mode and refresh its label. */
void func_004BAF40(int a)
{
    if (a) {
        int b = D_00171DB8[0].f8 == 0;
        D_00171DB8[0].f8 = b;
        func_001586B8(b ^ 1);
        func_004985F0(16);
    }
    func_005062D0(func_004A2798(&D_002218E0, D_003D95AC[0]), D_0030A540 + D_00171DB8[0].f8 * 48);
}
