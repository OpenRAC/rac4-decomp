#include "common.h"

typedef int u128 __attribute__((mode(TI)));
typedef u128 Quadword;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;
extern Quadword func_L01_0045B2F8(const u8 *object);
extern Vec func_L01_0045B358(void *arg0);
extern s32 func_L01_0045BEE0(void *arg0);
extern s32 func_L01_0056EE18(u128 a0, s32 a1, Quadword a2, void *a3, void *a4, s32 a5);
extern s32 func_L01_005A8B48(u128 a0);

/* Run the helpers on the object's linked record, then store the result of func_L01_005A8B48 at its +0x5F4. */
s32 func_L01_0045BC08(u8 *arg0, u128 arg1)
{
    u8 *linked = *(u8 **)(arg0 + 0xAC);
    s32 f410 = *(s32 *)(linked + 0x410);
    s32 key;
    u8 *cell;
    Quadword q;
    Vec buf;
    s32 r;

    if (f410 != 0) {
        key = f410 + 0x2A0;
        q = func_L01_0045B2F8(arg0);
        cell = linked + 0x5A0;
        buf = func_L01_0045B358(arg0);
        r = func_L01_0045BEE0(arg0);
        if (func_L01_0056EE18(arg1, key, q, &buf, cell, r) != 0) {
            *(s32 *)(linked + 0x5F4) = func_L01_005A8B48(*(u128 *)(linked + 0x5A0));
            return 1;
        }
    }
    return 0;
}
