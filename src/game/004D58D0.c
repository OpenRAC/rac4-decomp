#include "common.h"
typedef struct {
    char p0[0x50];
    s32 f50;
} Type1;
extern Type1 D_0031CCC4[];
extern s32 D_0031B9B8[];
extern void func_004A1358(Type1 *);
extern void func_004A1310(Type1 *);
extern s32 func_004E21D8(s32, s32, s32);
extern s32 func_004E0858(void);

/* Changes selection, marks the dirty flag and refreshes the view. */
void func_004D58D0(s32 a)
{
    if (D_0031CCC4[0].f50 >= 2) {
        if (a)
            func_004A1358(D_0031CCC4);
        else
            func_004A1310(D_0031CCC4);
        D_0031B9B8[1] |= 2;
        func_004E21D8(0, 0, 0);
        func_004E0858();
    }
}
