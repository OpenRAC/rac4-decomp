#include "common.h"
typedef struct { u16 f0; s16 f2, f4, f6; s32 f8, fc; u32 f10; s32 f14, f18; char pad[0x24]; u8 f40; char tail[0xf]; } Entry;
extern Entry D_003232C0[];
/* Initialize the twelve records. */
void func_004E2568(void) {
    Entry *p = D_003232C0;
    Entry *end = p + 12;
    do {
        p->f40 = 0;
        p->f2 = -1;
        p->f4 = -1;
        p->f6 = -1;
        p->fc = 0;
        p->f8 = 0;
        p->f0 = 0xffff;
        p->f10 = 0xffffffffU;
        p->f14 = 0;
        p->f18 = -1;
        p++;
    } while ((s32)p < (s32)end);
}
