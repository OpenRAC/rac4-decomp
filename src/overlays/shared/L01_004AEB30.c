#include "common.h"

extern s32 func_L01_0056A828(void *, s32);
extern s32 D_003B7870[];
extern u8 *D_222D14;
extern u8 *D_222D2C;

// Count objects matching the given id (or all ids when -1), asking 0x2112 objects through func_L01_0056A828.
s32 func_L01_004AEB30(s32 arg0) {
    u8 *p;
    s32 count = 0;
    s32 i;

    for (p = D_222D14; p < D_222D2C; p += 0x100) {
        if ((arg0 == -1 || arg0 == D_003B7870[16]) && *(s16 *)(p + 0xBC) == D_003B7870[16]) {
            count++;
        } else if (*(s16 *)(p + 0xBC) == 0x2112) {
            if (arg0 == -1) {
                for (i = 0; i < 20; i++) {
                    count += func_L01_0056A828(*(void **)(p + 0xAC), D_003B7870[i]);
                }
            } else {
                count += func_L01_0056A828(*(void **)(p + 0xAC), arg0);
            }
        }
    }
    return count;
}
