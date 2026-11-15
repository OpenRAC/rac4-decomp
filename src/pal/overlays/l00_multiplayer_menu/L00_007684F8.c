#include "common.h"

/* Set only the field observed in this object method. */
typedef struct Type1 {
    u8 pad0[0x278];
    u8 f278;
} Type1;

void func_L00_007684F8(Type1 *object) {
    object->f278 = 1;
}
