#include "common.h"

extern s32 func_00667008(s32 a0);
extern s32 func_L00_006EBF70(s32 p, s32 a1, s32 a2);

/* Resolve the handle and hand the two arguments to the target pass; a failed
   lookup reports 0. */
s32 func_L01_006B5028(s32 a0, s32 a1, s32 a2)
{
    s32 p = func_00667008(a0);

    if (p != 0) {
        return func_L00_006EBF70(p, a1, a2);
    }
    return 0;
}
