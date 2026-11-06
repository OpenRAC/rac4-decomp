#include "common.h"

/* Native guarded flag predicate; preserves signed-byte and halfword loads. */

s32 func_L41_00441F38(void *arg0) {
    void *temp_v1;

    if (*(s32 *)0x21E714 == 1) {
        temp_v1 = *(void **)0x21E078;
        if (((*(s8 *)((s8 *)(temp_v1) + (9))) != 0) && ((*(s8 *)((s8 *)(temp_v1) + (0x23))) != 0)) {
            if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xAC)))) + (4))) == 0xA) {
                return (*(u16 *)((s8 *)(arg0) + (0x34))) & 1;
            }
            return 1;
        }
    }
    return (*(u16 *)((s8 *)(arg0) + (0x34))) & 1;
}
