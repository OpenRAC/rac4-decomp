/* cflags: -mno-split-addresses */
#include "pal/command_buffer.h"
extern char D_00003EB0[];
extern char D_00003E90[];


void func_004F64B8(PalCommandCursor *p, int *count, int a, int b, int c, int d, int e) {
    int delta = c - a;
    int n = delta >> 9;
    *p->words++ = *count | 0x6c038000;
    *p->words++ = 0x8002;
    *p->words++ = 0x20000000;
    *p->words++ = 0x5f;
    *p->words++ = n;
    p->words[2] = d;
    p->words += 4;
    *p->words++ = a;
    *p->words++ = b;
    *p->words++ = e;
    *p->words++ = delta / n;
    *p->words++ = ((int)D_00003EB0 >> 3) | 0x14000000;
    *count += 10;
    *p->words++ = *count | 0x64018000;
    *p->words++ = 0x8001;
    *p->words++ = 0x10000000;
    *p->words++ = *count | 0x72028000;
    *p->words++ = 0x3f0e;
    *p->words++ = ((int)D_00003E90 >> 3) | 0x14000000;
    *count += 2;
}
