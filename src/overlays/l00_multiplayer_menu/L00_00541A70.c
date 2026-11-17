/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_0052ADF0(void *arg0, s32 arg1);

typedef struct {
    s32 count;
    s32 *items;
} List;

// Finds arg1 in the list and calls the handler with its index.
s32 func_L00_00541A70(List *arg0, s32 arg1) {
    s32 i;
    s32 n;
    s32 *items;

    n = arg0->count;
    for (i = 0; i < n; i++) {
        items = arg0->items;
        if (items[i] == arg1) {
            return func_L00_0052ADF0(arg0, i);
        }
    }
    return 0;
}
