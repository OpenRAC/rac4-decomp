#include "common.h"
typedef struct { u8 pad0[0x20]; s32 key; u8 pad1[2]; u16 next; u8 pad2[0x8]; } Ent;
extern u16 D_0024D120[];
extern Ent D_0024F120[];
s32 func_L01_00571C50(u16 idx, u16 val, s32 *out)
{
    u16 cur;
    if (idx >= 0x1000) {
        return 1;
    }
    if (val == 0x801) {
        return 0;
    }
    cur = D_0024D120[idx];
    while (cur != 0x801) {
        if (cur == val) {
            if (out != 0) {
                *out = D_0024F120[val].key;
            }
            return 1;
        }
        cur = D_0024F120[cur].next;
    }
    return 0;
}
