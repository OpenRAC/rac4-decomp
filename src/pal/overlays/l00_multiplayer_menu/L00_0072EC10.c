#include "common.h"

/* Set only the field observed in this object method. */
typedef struct Type1 {
    u8 pad0[0x260];
    s32 f260;
} Type1;

void func_L00_0072EC10(Type1 *object) {
    object->f260 = 0x200;
}
