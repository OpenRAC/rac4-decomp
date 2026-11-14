#include "common.h"

extern s32 func_L05_003E4370();
extern void *D_363038[];

// Scans the ten slots of D_363038: a slot holding an object whose 0x2F0 word is set gives 1 when its 0x2EC word equals arg0, else 0; the first value that differs from the call's result is returned, else that result.
s32 func_L05_003E4078(s32 arg0) {
    s32 temp;
    s32 i;
    s32 a0;
    s32 x;
    void **p;
    u8 *obj;

    temp = func_L05_003E4370();
    i = 0;
    p = D_363038;
    obj = D_363038[0];
    do {
        if (obj != NULL) {
            a0 = 0;
            if (*(s32 *)(obj + 0x2F0) != 0) {
                x = *(s32 *)(obj + 0x2EC);
                if ((x ^ arg0) == 0) {
                    a0 = 1;
                }
            }
            if (a0 != temp) {
                return a0;
            }
        }
        p++;
        i++;
        obj = *p;
    } while (i < 10);
    return temp;
}
