#include "common.h"

extern s32 func_0046AAC0(s32 arg0, s32 arg1);
extern void *func_0054A998(s32 arg0);
extern s32 func_0054AA58(s32 arg0);
extern s32 func_0054AAD8(s32 arg0);
extern s32 func_0054AB08(s32 arg0, s32 arg1);

/* Counts the entries of arg0 whose tag is 1 and that func_0046AAC0 reports set. */
s32 func_004C0DD0(s32 arg0)
{
    s32 count;
    s32 n;
    s32 i;
    s32 flag;
    s32 next;

    count = 0;
    n = func_0054AA58(func_0054AAD8(arg0));
    for (i = 0; i < n; i++) {
        if (*(s32 *)((char *)func_0054A998(func_0054AB08(arg0, i)) + 0x14) == 1) {
            flag = func_0046AAC0(arg0, i);
            next = count + 1;
            if (flag) {
                count = next;
            }
        }
    }
    return count;
}
