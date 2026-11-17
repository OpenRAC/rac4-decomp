#include "common.h"

/* Set only the field observed in this object method. */
typedef struct Type1 {
    u8 pad0[0x66C];
    u8 f66C;
} Type1;

void func_L00_0074EBD8(Type1 *object) {
    object->f66C = 1;
}
