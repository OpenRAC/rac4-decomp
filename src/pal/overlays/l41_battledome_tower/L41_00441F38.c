/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_0021E714[];
extern void *D_0021E078[];

/* Native guarded flag predicate; preserves signed-byte and halfword loads. */

s32 func_L41_00441F38(void *arg0) {
    void *temp_v1;

    if (D_0021E714[0] == 1) {
        temp_v1 = D_0021E078[0];
        if (((*(s8 *)((s8 *)(temp_v1) + (9))) != 0) && ((*(s8 *)((s8 *)(temp_v1) + (0x23))) != 0)) {
            if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xAC)))) + (4))) == 0xA) {
                return (*(u16 *)((s8 *)(arg0) + (0x34))) & 1;
            }
            return 1;
        }
    }
    return (*(u16 *)((s8 *)(arg0) + (0x34))) & 1;
}
