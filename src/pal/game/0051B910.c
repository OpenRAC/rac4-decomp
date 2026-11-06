#include "common.h"

extern void func_0046C6B0(void *);

/* Release the attached object and restore the default motion factors. */
void func_0051B910(char *p)
{
    f32 a, b, c, d;
    if (*(void **)(p + 0x1C54)) {
        func_0046C6B0(*(void **)(p + 0x1C54));
        *(void **)(p + 0x1C54) = 0;
    }
    if (*(s16 *)(p + 0x3A0))
        *(s16 *)(p + 0x3A0) = 0;
    a = 1.05f;
    b = 0.7f;
    c = 0.45f;
    d = 0.2025f;
    *(f32 *)(p + 0x1F0) = a;
    *(f32 *)(p + 0x1F4) = b;
    *(f32 *)(p + 0x204) = c;
    *(f32 *)(p + 0x240) = d;
    *(f32 *)(p + 0x1F8) = a;
    *(f32 *)(p + 0x1FC) = b;
}
