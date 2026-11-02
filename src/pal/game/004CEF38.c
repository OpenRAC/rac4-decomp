#include "common.h"
typedef struct {
    char p0[0x50];
    s32 f50;
} Type1;
extern char D_0030ECC0[];
extern s32 func_00506BB8(void);
extern void func_004A2090(Type1 *);
extern void func_004A2048(Type1 *);
extern s32 func_004E3138(s32, s32, s32);
extern s32 func_004E17B8(void);

/* Changes the active selection and marks its record dirty. */
void func_004CEF38(s32 a)
{
    char *p = D_0030ECC0 + func_00506BB8() * 640;
    Type1 *q = (Type1 *)(p + 0x210);
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
