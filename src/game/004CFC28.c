#include "common.h"

/* PAL reconstruction reviewed against the exact retail interval;
 * source-family reference: func_004CEF38. */
typedef struct {
    char p0[0x50];
    s32 f50;
} Type1;
extern char D_00316D00[];
extern s32 func_00505B20(void);
extern void func_004A1358(void *);
extern void func_004A1310(void *);
extern s32 func_004E21D8(s32, s32, void *);
extern s32 func_004E0858(void);

/* Changes the active selection and marks its record dirty. */
void func_004CFC28(s32 a)
{
    char *p = D_00316D00 + func_00505B20() * 2528;
    Type1 *q = (Type1 *)(p + 2420);
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
