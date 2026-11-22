#include "common.h"
typedef struct { u8 pad0[0x20]; s32 key; u8 pad1[2]; u16 next; u8 pad2[0x8]; } Ent;
extern u16 D_0024D120[];
extern Ent D_0024F120[];
s32 func_L01_00571BD0(u16 idx, s32 key, u16 *out)
{
    u16 cur;
    if (idx >= 0x1000) {
        return 1;
    }
    cur = D_0024D120[idx];
    while (cur != 0x801) {
        if (D_0024F120[cur].key == key) {
            if (out != 0) {
                *out = cur;
            }
            return 1;
        }
        cur = D_0024F120[cur].next;
    }
    return 0;
}
