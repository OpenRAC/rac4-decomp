#include "common.h"
typedef struct {
    char p0[0x50];
    s32 f50;
} Type1;
extern char D_0030ECC0[];
extern s32 func_00505B20(void);
extern void func_004A1358(Type1 *);
extern void func_004A1310(Type1 *);
extern s32 func_004E21D8(s32, s32, s32);
extern s32 func_004E0858(void);

/* Changes the active selection and marks its record dirty. */
void func_004CE098(s32 a)
{
    char *p = D_0030ECC0 + func_00505B20() * 640;
    Type1 *q = (Type1 *)(p + 0x210);
    if (q->f50 >= 2) {
        if (a)
            func_004A1358(q);
        else
            func_004A1310(q);
        func_004E21D8(0, 0, 0);
        func_004E0858();
        *(s32 *)(p + 8) |= 6;
    }
}
