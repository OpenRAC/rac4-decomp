#include "common.h"
typedef struct Type1 {
    char p[0xBC];
    unsigned char fBC;
} Type1;
extern Type1 D_00171D38[];
extern void func_00497980(int);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505238(s32, const char *);
extern const char *func_0045E038(s32);
extern int D_00221790;
extern int D_003D93E0[];
int D_0021F880[2] = {
    0x14F1, 0x14F0};
/* Toggle the display option and refresh its resource label. */
void func_004B8888(int a)
{
    s32 p;
    if (a) {
        D_00171D38[0].fBC = !D_00171D38[0].fBC;
        func_00497980(16);
    }
    p = func_004A1A60(&D_00221790, D_003D93E0[0]);
    func_00505238(p, func_0045E038(D_0021F880[D_00171D38[0].fBC]));
}
