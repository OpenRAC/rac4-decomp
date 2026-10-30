#include "common.h"

extern void *func_0048A970(u32 arg0);

// Looks up the record for id; when found, stores fparg0 at +0x30 and fparg1 at +0x34 and returns 1, else 0.
s32 func_0048A430(s32 unused0, s32 id, f32 fparg0, f32 fparg1) {
    s32 result = 0;
    u8 *obj;

    obj = func_0048A970(id);
    if (obj != NULL) {
        *(f32 *)(obj + 0x30) = fparg0;
        result = 1;
        *(f32 *)(obj + 0x34) = fparg1;
    }
    return result;
}
