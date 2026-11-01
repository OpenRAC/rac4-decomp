/* cflags: -O2 -G8 -Wa,-G0 */
#include "common.h"

void func_0050FF90(void *object, f32 value) {
    void *state = *(void **)((u8 *)object + 0x40);
    *(f32 *)((u8 *)state + 0x48) = value * 0.8333333f;
}
