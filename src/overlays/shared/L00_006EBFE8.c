#include "common.h"

extern void func_L00_006EC228(u8 *entry);
extern s32 D_002233A0;
extern u8 D_172160[];
u8 *D_002206AC = 0;
u8 *D_002206B0 = 0;

// Move the entries that have not ended onto the deferred list, then release the marked deferred entries.
void func_L00_006EBFE8(void) {
    u8 *prev;
    u8 *p;
    u8 *next;
    u8 *g;

    prev = 0;
    p = D_002206AC;
    if (p != 0) {
        g = D_172160;
        do {
            if (p[0x55] == 0 && !(*(s32 *)(g + 0x218) < *(s32 *)(p + 4) + (s32)(*(u32 *)p >> 14))) {
                next = *(u8 **)(p + 0x58);
                if (prev == 0) {
                    D_002206AC = next;
                } else {
                    *(u8 **)(prev + 0x58) = next;
                }
                *(u8 **)(p + 0x58) = D_002206B0;
                D_002206B0 = p;
                p = next;
            } else {
                prev = p;
                p = *(u8 **)(p + 0x58);
            }
        } while (p != 0);
    }
    p = D_002206B0;
    while (p != 0) {
        if (*(s32 *)(p + 0x50) == -1 || *(s32 *)(p + 0x50) == D_002233A0) {
            func_L00_006EC228(p);
        }
        p = *(u8 **)(p + 0x58);
    }
}
