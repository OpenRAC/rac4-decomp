#include "common.h"

/* PAL reconstruction reviewed against the exact retail interval;
 * source-family reference: func_004CEF38. */
typedef struct {
    char p0[0x50];
    s32 f50;
} Type1;
extern char D_0030F820[];
extern s32 func_00506BB8(void);
extern void func_004A2090(void *);
extern void func_004A2048(void *);
extern s32 func_004E3138(s32, s32, void *);
extern s32 func_004E17B8(void);

/* Changes the active selection and marks its record dirty. */
void func_004CFDB8(s32 a)
{
    char *p = D_0030F820 + func_00506BB8() * 4156;
    Type1 *q = (Type1 *)(p + 3984);
    if (q->f50 >= 2) {
        if (a)
            func_004A2090(q);
        else
            func_004A2048(q);
        func_004E3138(0, 0, 0);
        func_004E17B8();
        *(s32 *)(p + 8) |= 6;
    }
}
