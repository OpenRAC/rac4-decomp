#include "common.h"

typedef struct {
    u8 pad[0xBC];
    s16 fBC;
} Type1;

/* Whether the object (when there is one) has type 0x23FA at +0xBC. */
s32 func_L00_006BEC80(s32 unused, Type1 *o) {
    if (o == 0) {
        return 0;
    }
    return o->fBC == 0x23FA;
}
