#include "common.h"

typedef struct {
    u8 pad00[0x74];
    u16 f74;
} Object;

void func_004D6AC8(Object *first, Object *second, u32 index)
{
    if (index < 5) {
        first->f74 = 1U << index;
        second->f74 = 0;
    } else {
        index -= 5;
        if (index < 3) {
            first->f74 = 0;
            second->f74 = 1U << index;
        }
    }
}
