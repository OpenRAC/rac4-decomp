/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 count;
    s32 *items;
} Type1;

extern void func_L00_00535E08(void *, s32, s32, s32, s32);
extern s32 func_L00_00535FB0(s32, s32, s32);

s32 func_L00_00536AC0(Type1 *list, s32 *out, s32 (*fn)(s32, void *), s32 arg3, s32 arg4) {
    s32 buf[4];
    s32 total;
    s32 i;
    s32 ret;

    total = 0;
    if (list == NULL) {
        return 0;
    }
    for (i = list->count - 1; i >= 0; i--) {
        total += fn(list->items[i], NULL);
    }
    ret = func_L00_00535FB0(1, total, arg3);
    if (out == NULL) {
        return ret;
    }
    buf[0] = *out;
    func_L00_00535E08(buf, 1, total, arg3, arg4);
    for (i = 0; i < list->count; i++) {
        fn(list->items[i], buf);
    }
    *out = buf[0];
    return ret;
}
