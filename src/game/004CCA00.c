#include "common.h"

extern s32 func_0045E038(s32);
extern void *func_0047D250(u32 index);
extern const char *func_004CCB18(void);
extern s32 func_004CCDC0(s32);
extern s32 func_004CCFD8(s32 i);
extern s32 func_00505B20(void);
extern void *func_00548D28(s32 arg0, s32 arg1);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern char D_0030EAA0[];

/* Look up the name text id for a slot and resolve it. */
s32 func_004CCA00(s32 arg0)
{
    char *p = D_0030EAA0 + func_00505B20() * 100;
    s32 id;
    s32 idx;

    if (arg0 == 8) {
        s32 tbl[6] = { 0x32A8, 0x32A9, 0x32AA, 0x32AB, 0x32AC, 0x32AC };
        id = tbl[*(s32 *)(p + 0x38)];
    } else if (arg0 == 9) {
        return (s32)func_004CCB18();
    } else {
        if (D_0021EDD4 != 0 || D_0021EDD8 != 1) {
            if (arg0 < 8) {
                id = *(s16 *)((char *)func_0047D250(func_004CCDC0(arg0)) + 4);
                goto done;
            }
            idx = func_004CCDC0(arg0);
        } else {
            idx = func_004CCFD8(arg0);
        }
        id = *(s16 *)((char *)func_00548D28(idx, 0) + 0xA);
    }
done:
    return func_0045E038(id);
}
