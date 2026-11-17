/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b0; u8 b1; } U2;
typedef struct { u32 f0; u32 f4; u8 data[0x12]; } Pkt;
typedef struct { u16 len; u16 flags; u16 hl; } HInfo;
extern void *memcpy(void *, const void *, unsigned int);
s32 func_01EBFD78(Pkt *p, void *out) {
    HInfo h;
    U2 *hp = (U2 *)((p ? p->data : 0) + 0x10);
    ((U2 *)&h.len)->b0 = hp->b0; ((U2 *)&h.len)->b1 = hp->b1;
    h.len &= 0x7FF;
    ((U2 *)&h.flags)->b0 = hp->b0; ((U2 *)&h.flags)->b1 = hp->b1;
    h.flags &= 0xF800;
    if (h.flags & 0x6000) {
        h.hl = 4;
    } else {
        h.hl = 2;
    }
    if (p != 0 && h.hl + h.len < p->f0) {
        memcpy(out, (u8 *)p + p->f0 + 4, 4);
        return 0;
    }
    *(u32 *)out = 0;
    return 0;
}
