/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 count;
    u8 **items;
} Type1;

extern s32 func_L00_00508600(u8 *a0);
extern s32 func_L00_0052D4C0(s32 a0, s32 a1);

u8 *func_L00_00541AD0(Type1 *arg0, s32 arg1) {
    s32 i;
    u8 *item;

    for (i = 0; i < arg0->count; i++) {
        item = arg0->items[i];
        if (func_L00_0052D4C0(func_L00_00508600(item), arg1) == 0) {
            return item;
        }
    }
    return 0;
}
