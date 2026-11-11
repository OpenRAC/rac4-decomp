#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
} Type1;

/* True when the first word of the eight-byte value passed by value is zero. */
s32 func_01EB4DD0(Type1 arg0) {
    return arg0.f0 == 0;
}
