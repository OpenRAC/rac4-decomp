#include "common.h"

extern s32 func_00506BB8(void);
extern void func_004A1EA8(void *);
extern void func_004A2178(void *, s32 *, s32);
extern s32 D_00321AE0[];
extern char D_00321650[];
/* Rebuild seven indexed items and clear the pending initialization bit. */
void func_004DA8D0(void)
{
    s32 i = 0;
    s32 *q;
    char *p = D_00321650 + func_00506BB8() * 0x124;
    func_004A1EA8(p + 0xb4);
    q = D_00321AE0;
    do {
        func_004A2178(p + 0xb4, q, -1);
        *q = i;
        i++;
        q++;
    } while (i < 7);
    *(s32 *)(p + 8) &= ~1;
}
