/* cflags: -mno-split-addresses */
#include "common.h"

extern void *func_0046E100(s32);
extern s32 D_00223368[];

/* Writes four converted values, clearing the slot at index. */
void func_L00_0071BC90(s32 index)
{
    s32 i;
    s32 *slot;
    void *obj;

    slot = D_00223368;
    for (i = 0; i < 4; i++) {
        if (i != index) {
            obj = func_0046E100(i);
            if (obj != 0) {
                *slot = (s32)*(f32 *)((u8 *)obj + 0x44);
            }
        } else {
            *slot = 0;
        }
        slot++;
    }
}
