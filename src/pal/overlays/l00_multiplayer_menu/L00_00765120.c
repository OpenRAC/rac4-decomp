#include "common.h"

typedef struct {
    u8 pad00[0x230];
    s32 f230;
    u8 pad234[0x260 - 0x234];
    s32 f260;
    s32 f264;
    s32 f268;
    u8 pad26C[0x274 - 0x26C];
    s32 f274;
} Type1;

extern s32 func_L00_007697C0(s32 identifier);

/* Clear the object's pending word and store its step at offset 0x230. */
void func_L00_00765120(Type1 *object)
{
    s32 current;
    s32 step;

    object->f264 = 0;
    func_L00_007697C0(0xAF);
    current = object->f274;
    if (current < object->f268) {
        step = object->f260;
        step -= 0xC;
        object->f230 = current - step;
    } else {
        object->f230 = 0xC;
    }
}
