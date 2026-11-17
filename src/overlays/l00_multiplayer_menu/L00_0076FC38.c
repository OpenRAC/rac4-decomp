/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 D_002233A4;

typedef struct { u8 b[0x100]; } Blob1;
typedef struct { u8 pad[0x20]; s32 f20; Blob1 data; } Rec;

// Copies the 0x100-byte block at arg0+0x40 into the next record of the pool at D_002233A4->f48, then stores the flag.
void func_L00_0076FC38(u8 *arg0) {
    u8 *s2 = *(u8 **)(D_002233A4 + 0x48);
    Rec *r;
    s32 *cnt = (s32 *)(s2 + 0x1B00);
    if (*(s32 *)(arg0 + 0x18) == 0) {
        r = (Rec *)(s2 + 0x1B04) + (*cnt)++;
        r->f20 = *(s32 *)(arg0 + 0x1C);
        func_L00_005C1758((s32)r, (s32)(arg0 + 0x20), 0x20);
        r->data = *(Blob1 *)(arg0 + 0x40);
        if (*(u8 *)(arg0 + 0x144) != 1) return;
    }
    *(s8 *)(s2 + 0x20) = 0;
    *(s32 *)(s2 + 0x24) = *(s32 *)(arg0 + 0x18);
}
