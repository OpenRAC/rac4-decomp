#include "common.h"

extern void *func_L00_004FACD8(s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
} Type1;

// Allocates 0x18 bytes and sets its words to 0, 1, 1, 0 and 0 (at 0, 8, 0x10, 0xC and 0x14); when the allocation fails, calls func_L00_004F84C8 and returns NULL.
Type1 *func_L00_0051CEB0(void) {
    Type1 *temp_v0;

    temp_v0 = func_L00_004FACD8(0x18);
    if (temp_v0 != 0) {
        temp_v0->f0 = 0;
        temp_v0->f8 = 1;
        temp_v0->f10 = 1;
        temp_v0->fC = 0;
        temp_v0->f14 = 0;
        return temp_v0;
    }
    func_L00_004F84C8(6, 0x6B, 0x21, 0, 0);
    return 0;
}
