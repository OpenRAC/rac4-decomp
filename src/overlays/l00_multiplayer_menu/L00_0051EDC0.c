#include "common.h"

typedef struct Type2 {
    char pad[0x10];
    s32 (*f10)(void *, s32, s32, s32, s32, s32);
} Type2;
typedef struct Type1 {
    Type2 *f0;
} Type1;

/* Forwards its arguments to the object's vtable slot 0x10 with 8 inserted. */
s32 func_L00_0051EDC0(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return arg0->f0->f10(arg0, 8, arg1, arg2, arg3, arg4);
}
