/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b0; u8 b1; } U2;
typedef struct { u32 f0; u32 f4; u8 data[0x12]; } Pkt;
typedef struct { u16 len; u16 flags; u16 hl; } HInfo;
extern void *memcpy(void *, const void *, unsigned int);
s32 func_01EBFE28(Pkt *p, u32 v) {
    struct { HInfo h; u32 w; } s;
    U2 *hp = (U2 *)((p ? p->data : 0) + 0x10);
    s.w = v;
    ((U2 *)&s.h.len)->b0 = hp->b0; ((U2 *)&s.h.len)->b1 = hp->b1;
    s.h.len &= 0x7FF;
    ((U2 *)&s.h.flags)->b0 = hp->b0; ((U2 *)&s.h.flags)->b1 = hp->b1;
    s.h.flags &= 0xF800;
    if (s.h.flags & 0x6000) {
        s.h.hl = 4;
    } else {
        s.h.hl = 2;
    }
    if (p != 0 && s.h.hl + s.h.len < p->f0) {
        memcpy((u8 *)p + p->f0 + 4, &s.w, 4);
    }
    return 0;
}
