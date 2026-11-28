#include "common.h"
#include "pal/profile_001721E0.h"

typedef struct {
    u8 pad00[0x274];
    s32 f274;
} Type1;

s32 func_L00_00764EB8(const Type1 *object)
{
    return object->f274 != 8 ? D_001721E0.region20.words.f34 : D_001721E0.region20.words.fD8;
}
