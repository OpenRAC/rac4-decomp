#include "common.h"

typedef s32 (*Fn)(s32, s32, s32, u8, s16, s32);
typedef struct { Fn fn; } Obj;
Obj *func_0046D428(s32, s32, s32);
s32 func_00451230(s32 a, s32 b, s32 c, s32 d, u8 e, s16 f, s32 g) {
    Obj *o = func_0046D428(0x2034, 0, 4);
    if (o == 0) {
        return 0;
    }
    return o->fn(b, c, d, e, f, g);
}
