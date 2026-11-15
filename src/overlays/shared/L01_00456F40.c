#include "common.h"

extern s32 func_L01_00513E78();
extern s32 func_L01_00588B08(void *object);
extern s32 D_003A6A40[];
extern s32 D_003A6A58[];
extern s32 D_003A6A70[];
s32 D_002216F0 = 0;
s32 D_002216F4 = 0;
s32 D_002216F8 = 0;

/* One-time init of an object's extra block, then calls the update function. */
void func_L01_00456F40(u8 *o) {
    s32 *p = *(s32 **)(o + 0xAC);
    if (o[0x20] == 0) {
        o[0x20] = 1;
        p[5] = (s32)D_003A6A40;
        p[4] = (s32)D_003A6A58;
        p[3] = 5;
        p[1] = D_002216F0;
        p[6] = D_002216F4;
        p[7] = D_002216F8;
        p[2] = (s32)D_003A6A70;
        p[0] = 0;
        p[8] = D_002216F4;
        func_L01_00588B08(o);
    }
    func_L01_00513E78(o);
}
