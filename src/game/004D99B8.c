#include "common.h"

extern s32 func_00505B20(void);
extern void func_004A1170(void *);
extern void func_004A1440(void *, s32 *, s32);
extern s32 D_00321AE0[];
extern char D_00321650[];
/* Rebuild seven indexed items and clear the pending initialization bit. */
void func_004D99B8(void)
{
    s32 i = 0;
    s32 *q;
    char *p = D_00321650 + func_00505B20() * 0x124;
    func_004A1170(p + 0xb4);
    q = D_00321AE0;
    do {
        func_004A1440(p + 0xb4, q, -1);
        *q = i;
        i++;
        q++;
    } while (i < 7);
    *(s32 *)(p + 8) &= ~1;
}
