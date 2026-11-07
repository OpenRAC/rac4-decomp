/* Not matching yet: SIZE ours 64 / retail 88 (tools/try_func.py func_01EBF978 --diff). Not part of the build. */
#include "common.h"

// Unlink `node` from the 0x8C chain that starts at the 0xC head of `p`.
void func_01EBF978(u8 *p, u8 *node) {
    u8 *cur;
    u8 *next;

    if (*(u8 **)(p + 0xC) == node) {
        *(u8 **)(p + 0xC) = *(u8 **)(node + 0x8C);
        return;
    }
    cur = *(u8 **)(p + 0xC);
    if (cur == 0) {
        return;
    }
    next = *(u8 **)(cur + 0x8C);
    while (next != node) {
        cur = next;
        if (cur == 0) {
            return;
        }
        next = *(u8 **)(cur + 0x8C);
    }
    *(u8 **)(cur + 0x8C) = *(u8 **)(node + 0x8C);
}
