#include "common.h"

extern u8 *func_0011A518(u8 *, s32, s32);
extern s32 *D_003367B8[];

s32 D_00220E78 = 0;

s32 func_00540EC8(void)
{
    u8 bytes[11];
    s32 **p;
    s32 *obj;
    s32 index;
    s32 i;

    if (D_00220E78 == 0) {
        func_0011A518(bytes, 0, 11);
        p = D_003367B8;
        for (i = 9; i >= 0; i--) {
            obj = *p;
            if (obj != 0) {
                index = obj[3013];
                if (index < 11) {
                    if (bytes[index] == 0) {
                        D_00220E78++;
                        bytes[obj[3013]] = 1;
                    }
                }
            }
            p++;
        }
        if (D_00220E78 < 2) {
            D_00220E78 = 2;
        }
    }
    return D_00220E78;
}
