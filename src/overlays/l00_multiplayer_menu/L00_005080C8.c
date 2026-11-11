/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004CC2C8 (src/levels/39_multiplayer_menu/L39_004CBF70.c, GPL-3.0), the same code in both games. */

typedef s32 (*Cmp_004CC2C8)(const void *, const void *);
typedef struct Type1 {
    s32 count;
    s32 *items;
    s32 sorted;
    u8 padC[4];
    Cmp_004CC2C8 cmp;
} Type1;
extern void func_001203C0(void *, s32, s32, Cmp_004CC2C8);
extern void *func_0011EBB8(const void *, const void *, s32, s32, Cmp_004CC2C8);
s32 func_L00_005080C8(Type1 *t, s32 key) {
    s32 i;
    s32 *r;
    Cmp_004CC2C8 c = t->cmp;
    if (c == 0) {
        for (i = 0; i < t->count; i++) {
            if (t->items[i] == key) {
                return i;
            }
        }
        return -1;
    }
    if (t->sorted == 0) {
        func_001203C0(t->items, t->count, 4, c);
        t->sorted = 1;
    }
    if (key == 0) {
        return -1;
    }
    r = func_0011EBB8(&key, t->items, t->count, 4, c);
    if (r == 0) {
        return -1;
    }
    for (i = r - t->items; i > 0; i--) {
        if (t->cmp(&t->items[i - 1], &key) < 0) {
            break;
        }
    }
    return i;
}
