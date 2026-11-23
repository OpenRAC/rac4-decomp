#include "common.h"

extern s64 func_L01_004B9EC0(int objectbits);
extern s32 func_L01_004BAAE0(void *object);

f32 func_L01_004BABC0(void *object)
{
    void *payload = *(void **)((u8 *)object + 0xAC);
    s32 count;
    f32 numerator;
    f32 denominator;

    if (func_L01_004B9EC0((s32)object) != 0)
        goto one;
    if (func_L01_004BAAE0(object) != 0)
        return 0.0f;
    count = *(s32 *)((u8 *)payload + 0x284);
    if (count == 0) {
one:
        return 1.0f;
    } else {
        numerator = *(f32 *)((u8 *)payload + 0x280);
        denominator = (f32)count;
        return 1.0f - numerator / denominator;
    }
}
