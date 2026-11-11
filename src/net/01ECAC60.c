/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 *D_00167F38[];
extern u8 *D_1B7390[];
extern void *func_01EC9A08(u32);

/* Validate the index against the object's 0x10C limit, look the slot up and mark
   it; 0x17 and 9 are the refusal codes. */
s32 func_01ECAC60(u32 index)
{
    u8 *obj = D_00167F38[0];
    u8 *q;
    char *slot;

    if (index >= *(u32 *)(obj + 0x10C)) {
        return 0x17;
    }
    q = D_1B7390[0];
    if (q == 0) {
        return 9;
    }
    slot = (char *)func_01EC9A08(index);
    if (slot == 0) {
        return 9;
    }
    if (*(s32 *)(slot + 0xC) != *(s32 *)(q + 0x404)) {
        return 9;
    }
    *(u8 *)(slot + 4) = 1;
    return 0;
}
