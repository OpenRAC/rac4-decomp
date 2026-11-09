/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x24];
    s32 f24;
    char _p28[0x50];
    s32 f78;
    s32 f7C;
};

void func_01F0C090(void *, s32);
extern Type1 *D_0016E430;
extern s32 D_0019C400[];

s32 func_01EEE1FC(void) {
    s32 ret = 0;
    if (D_0016E430 != NULL) {
        if (D_0016E430->f24 != 0) {
            if (D_0016E430->f7C == 0) {
                func_01F0C090(D_0019C400, 0x83);
            }
            ret = D_0016E430->f7C;
        } else {
            if (D_0016E430->f78 == 0) {
                func_01F0C090(D_0019C400, 0x88);
            }
            ret = D_0016E430->f78;
        }
    }
    return ret;
}
