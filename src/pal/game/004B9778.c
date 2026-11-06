#include "common.h"
typedef struct Type1 {
    char p[0xBC];
    unsigned char fBC;
} Type1;
extern Type1 D_00171DB8[];
extern void func_004985F0(int);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005062D0(s32, const char *);
extern const char *func_0045E850(s32);
extern int D_00221890;
extern int D_003D9458[];
int D_0021F920[2] = {
    0x14F1, 0x14F0};
/* Toggle the display option and refresh its resource label. */
void func_004B9778(int a)
{
    s32 p;
    if (a) {
        D_00171DB8[0].fBC = !D_00171DB8[0].fBC;
        func_004985F0(16);
    }
    p = func_004A2798(&D_00221890, D_003D9458[0]);
    func_005062D0(p, func_0045E850(D_0021F920[D_00171DB8[0].fBC]));
}
