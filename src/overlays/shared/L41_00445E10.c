/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 *D_00222794;
extern u8 *D_002227B0;
s32 func_L41_00445DA0(s32 arg0, s32 arg1);

/* Calls func_L41_00445DA0 for each entry of type 0x261F/0x2628 whose key equals arg1; returns the count. */
s32 func_L41_00445E10(s32 arg0, s32 arg1) {
    u8 *p;
    s32 count;
    s32 i;

    count = 0;
    i = 0;
    for (p = D_00222794; p != D_002227B0; p += 0x100, i++) {
        if (p != NULL) {
            if (*(s16 *)(p + 0xBC) == 0x261F) {
                if ((*(s32 **)(p + 0xAC))[0x20] == arg1) {
                    func_L41_00445DA0(arg0, i);
                    count++;
                }
            } else if (*(s16 *)(p + 0xBC) == 0x2628) {
                if (**(s32 **)(p + 0xAC) == arg1) {
                    func_L41_00445DA0(arg0, i);
                    count++;
                }
            }
        }
    }
    return count;
}
