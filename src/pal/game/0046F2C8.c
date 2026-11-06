#include "common.h"
typedef struct {
    char pad[0x10];
    u8 frames;
    char gap[11];
    u8 *data;
} Object;
extern void func_0046A080(const void *, s32, u32), func_0046A0C0(void), func_0046E560(f32);
void func_0046F2C8(Object *p, f32 frame)
{
    s32 i = (s32)frame, j = i + 1;
    f32 frac = frame - i;
    u8 *d = p->data;
    s32 size = d[2], head = d[1];
    u8 *first, *second;
    if (j == p->frames)
        j = 0;
    i *= size;
    j *= size;
    first = d + (head + i) * 16;
    second = d + (j + head) * 16;
    if (head) {
        func_0046A080(d, head, 0x2000);
        func_0046A0C0();
    }
    if (size) {
        func_0046A080(first, size, 0x3000);
        func_0046A0C0();
        func_0046A080(second, size, 0x3800);
        func_0046A0C0();
    }
    func_0046E560(frac);
}
