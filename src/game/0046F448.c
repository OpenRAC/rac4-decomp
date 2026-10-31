#include "common.h"

extern void func_0046F068(u8 *entry);

// Releases every entry of the list headed at +0x50 (linked through +0x10), then clears the head.
void func_0046F448(u8 *arg0) {
    u8 *cur;
    u8 *next;

    cur = *(u8 **)(arg0 + 0x50);
    if (cur != NULL) {
        do {
            next = *(u8 **)(cur + 0x10);
            func_0046F068(cur);
            cur = next;
        } while (cur != NULL);
    }
    *(u8 **)(arg0 + 0x50) = NULL;
}
