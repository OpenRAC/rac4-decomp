#include "common.h"

extern s32 D_00220B50;

/* Calls the handler at +0x14 of arg0's +8 object with the global; returns arg0 if it reports nonzero, else NULL. */
void *func_00500AA0(void *arg0) {
    s32 (*fn)(void *, s32);
    s32 r;

    if (arg0 != NULL) {
        fn = *(s32 (**)(void *, s32))(*(u8 **)((u8 *)arg0 + 8) + 0x14);
        r = fn(arg0, D_00220B50);
        if (r != 0) {
            return arg0;
        }
    }
    return NULL;
}
