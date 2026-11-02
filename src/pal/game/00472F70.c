#include "common.h"

extern s32 func_00163410(void);

/* Return a random angle in the centered interval. */
f32 func_00472F70(void)
{
    return (f32)(func_00163410() - 0x4000) * 3.1415927410125732421875f * 0.00006103515625f;
}
