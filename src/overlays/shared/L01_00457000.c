#include "common.h"

extern s32 func_L01_00513E78();
extern s32 func_L01_00588B08(void *object);
s32 D_00221700 = 0;
s32 D_00221704 = 0;
s32 D_00221708 = 0;
s32 D_00221710 = 0;
s32 D_00221720 = 0;
s32 D_00221730 = 0;

/* One-time init of an object's extra block, then calls the update function. */
void func_L01_00457000(u8 *o) {
    s32 *p = *(s32 **)(o + 0xAC);
    if (o[0x20] == 0) {
        o[0x20] = 1;
        p[5] = (s32)&D_00221710;
        p[4] = (s32)&D_00221720;
        p[3] = 3;
        p[1] = D_00221700;
        p[6] = D_00221704;
        p[7] = D_00221708;
        p[2] = (s32)&D_00221730;
        p[0] = 0;
        p[8] = D_00221704;
        func_L01_00588B08(o);
    }
    func_L01_00513E78(o);
}
