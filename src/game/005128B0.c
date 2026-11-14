/* cflags: -ffast-math */
#include "common.h"

// Adds arg1 to the float at 0x2E20 and clamps it to the float at 0x2F24; sets the s32 at 0x2ED8 to 0x168 and, when the object at 0x2F28 has a non-null sub-object at +4, stores the clamped value at +0x44 of that sub-object.
void func_005128B0(void *arg0, f32 arg1) {
    u8 *p = arg0;
    f32 a;
    f32 b;
    f32 m;
    void *obj;
    void *sub;

    if (p[0x266D] == 0) {
        return;
    }
    if (arg1 <= 0.0f) {
        return;
    }
    a = *(f32 *)(p + 0x2E20) + arg1;
    b = *(f32 *)(p + 0x2F24);
    *(s32 *)(p + 0x2ED8) = 0x168;
    m = a > b ? b : a;
    *(f32 *)(p + 0x2E20) = m;
    obj = *(void **)(p + 0x2F28);
    if (obj != NULL) {
        sub = *(void **)((u8 *)obj + 4);
        if (sub != NULL) {
            *(f32 *)((u8 *)sub + 0x44) = m;
        }
    }
}
