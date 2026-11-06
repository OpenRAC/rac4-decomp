#include "common.h"

/* Appends the command fields when the object state differs from the current value. */
typedef struct {
    u8 enabled;
    char pad[0x37];
    u64 value;
} Object;
extern u64 D_003D7720[];
extern u32 *D_00221F20;
extern char D_003D7790[];
void func_0044D8E0(Object *p)
{
    if (!p->enabled || p->value != D_003D7720[0]) {
        D_00221F20[0] = 0x30000002;
        D_00221F20[1] = (u32)D_003D7790;
        D_00221F20[2] = 0;
        D_00221F20[3] = 0x50000002;
        D_00221F20 += 4;
    }
}
