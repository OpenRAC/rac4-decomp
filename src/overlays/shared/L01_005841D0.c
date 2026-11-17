/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_00653498(void);
extern void *func_006C1008(s32);
extern s32 func_L00_00702608(s32, s32);
extern s32 *func_L01_00584068(s32);
extern s32 func_L01_00584268(s32 arg0);
extern s32 D_00220000[];
s32 D_0021EBD8 = 0;

// If the entry for the current index matches, queues the next entry's value when its object has no pending flag.
void func_L01_005841D0(void) {
    s32 *a;
    s32 next;
    s32 *b;

    a = func_L01_00584068(D_0021EBD8);
    if (*a == func_00653498()) {
        next = D_0021EBD8 + 1;
        b = func_L01_00584068(next);
        if (*b != -1) {
            if (*(s32 *)((u8 *)func_006C1008(func_L00_00702608(D_00220000[-0x21F0 / 4], next)) + 0x14) == 0) {
                func_L01_00584268(*b);
            }
        }
    }
}
