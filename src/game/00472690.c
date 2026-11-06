#include "common.h"

extern s32 func_00163408(void);

/* A random angle: (func_00163408() - 0x4000) scaled by pi / 16384. */
f32 func_00472690(void) {
    return (f32)(func_00163408() - 0x4000) * 3.1415927f * (1.0f / 16384.0f);
}
