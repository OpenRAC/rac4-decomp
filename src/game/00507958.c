#include "common.h"

extern s32 D_00220B54;
// Return arg0 when its method at +0x14 of its +8 table accepts D_00220B54, else NULL.
void *func_00507958(void *arg0) {
    u8 *object = arg0;
    s32 r;

    if (object != NULL) {
        r = (*(s32 (**)(void *, s32))(*(u8 **)(object + 8) + 0x14))(arg0, D_00220B54);
        if (r != 0) {
            return arg0;
        }
    }
    return NULL;
}
