#include "common.h"
extern void func_004985F0(int);
extern void func_004BBB50(int);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, const char *);
extern int D_002218E0;
extern int D_003D9624[];
unsigned char D_0021F97A = 0;
extern unsigned char D_0021F978;
extern int D_0021DEF4;
extern char D_0030A4E0[];
/* Select the panel mode and refresh its displayed text. */
void func_004BBAD8(int a)
{
    s32 p;
    if (!a) {
        func_004985F0(4);
        func_004BBB50(0);
    } else
        func_004985F0(11);
    D_0021F97A = 0;
    D_0021F978 = 0;
    p = func_004A2798(&D_002218E0, D_003D9624[0]);
    func_005062D0(p, D_0030A4E0 + D_0021DEF4 * 48);
}
