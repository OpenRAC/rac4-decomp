/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    u8 pad4[2];
    u16 f6;
    u8 pad8[4];
    u16 fC;
} Type1;

/* Reset the fields when a record is supplied. */
s32 func_L01_005756D8(Type1 *obj) {
    if (obj != NULL) {
        obj->f6 = 0;
        obj->fC = 0xFFFF;
        obj->f0 = 0;
        return 1;
    }
    return 1;
}
