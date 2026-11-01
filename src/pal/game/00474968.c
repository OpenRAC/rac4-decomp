#include "common.h"

typedef int quad __attribute__((mode(TI)));
extern void func_004748C0(quad position, f32 first, f32 second, s32 flags, s32 mode);

/* Preserve the packed position while supplying the default drawing parameters. */
void func_00474968(quad position)
{
    func_004748C0(position, 0.5f, 32.0f, 32, 0);
}
