#include "common.h"

s32 D_00221880 = 0;
s32 D_00221888 = 0;
s32 D_00221890 = 0;

/* from rac3-decomp's func_L01_003A0710 */
s32 *func_L01_00465BF8(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 21:
        *a2 = 4;
        return &D_00221880;
    case 20:
        *a2 = 8;
        return &D_00221888;
    case 19:
        *a2 = 12;
        return &D_00221890;
    }
    return 0;
}
