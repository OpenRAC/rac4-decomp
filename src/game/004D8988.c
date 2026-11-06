#include "common.h"

extern s32 func_00505B20(void);
extern void func_004A1170(void *);
extern void func_004A1440(void *, s32 *, s32);
extern s32 D_00321028[];
extern char D_00320178[];
/* Rebuild 34 indexed items and clear the pending initialization bit. */
void func_004D8988(void)
{
    s32 i = 0;
    s32 *q;
    char *p = D_00320178 + func_00505B20() * 0x3AC;
    func_004A1170(p + 0x340);
    q = D_00321028;
    do {
        func_004A1440(p + 0x340, q, -1);
        *q = i;
        i++;
        q++;
    } while (i < 34);
    *(s32 *)(p + 8) &= ~1;
}
