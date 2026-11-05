/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 func_L00_005208E8(s32, s32, s32, s32, void *, s32);

s32 func_L00_005190D8(s32 *arg0) {
    struct Item { s32 pad0; s32 pad4; s32 pad8; u8 *text; s32 count; } *item;
    struct { struct Item *item; } result __attribute__((aligned(16)));
    s32 count = 0;
    if (func_L00_005208E8(arg0[1], 0x12, 1, 0, &result, 0) == 0) {
        item = result.item;
        count = item->count;
        if (count > 0 && *item->text == 0) count--;
    }
    return count;
}
