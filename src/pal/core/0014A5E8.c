/* cflags: -fno-opt-stack */
#include "common.h"
typedef struct {
    s32 count;
    s32 cursor;
    const f32 *values;
} Ring;
extern s32 func_0014A6A8(s32 offset, s32 cursor, s32 count);
extern void func_001481C0(void *destination, const void *source, u32 bytes);
void func_0014A5E8(const Ring *ring, s32 position, s32 length, void *destination)
{
    s32 half = (s32)((u32)length + 1u) >> 1;
    s32 offset = (s32)(0u - ((u32)position + (u32)half));
    s32 count = ring->count;
    s32 cursor = ring->cursor;
    const f32 *values = ring->values;
    s32 start = func_0014A6A8(offset, cursor, count);
    s32 available = (s32)((u32)count - (u32)start);
    if (available >= length) {
        func_001481C0(destination, (const void *)((u32)values + (u32)start * 4u), (u32)length * 4u);
    } else {
        u32 bytes = (u32)available * 4u;
        func_001481C0(destination, (const void *)((u32)values + (u32)start * 4u), bytes);
        func_001481C0((void *)((u32)destination + bytes), values,
                      ((u32)length - (u32)available) * 4u);
    }
}
