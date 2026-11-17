/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } Tag;
s32 func_01EE1808(Tag *t, u8 *p) {
    u32 c = *p++;
    s32 n = 1;
    t->f4 = c & 0xC0;
    t->f8 = c & 0x20;
    t->fC = c & 0x1F;
    t->f0 = c;
    if (c != 0) {
        u32 l = *p++;
        n = 2;
        t->f10 = l;
        if (l & 0x80) {
            if (l == 0x81) {
                t->f10 = *p++;
                n = 3;
            } else if (l == 0x82) {
                t->f10 = *p++ << 8;
                t->f10 += *p++;
                n = 4;
            }
        }
    }
    if (t->f0 == 3 && *p == 0) {
        n++;
        t->f10--;
    }
    return n;
}
