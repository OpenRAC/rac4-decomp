#include "common.h"

extern void func_004994E0(void *arg0);
extern u8 D_2F3950[];

/* Scan the 0x280-byte table at D_2F3950 in 0x14-byte steps for an entry whose word at offset 4 equals arg0, then call func_004994E0 on it. */
void func_00499CE0(s32 arg0) {
    s32 *p = (s32 *)D_2F3950;
    s32 *end = (s32 *)(D_2F3950 + 0x280);

    while (1) {
        if (p[1] == arg0) {
            func_004994E0(p);
            return;
        }
        p += 5;
        if ((s32)p >= (s32)end) {
            return;
        }
    }
}
