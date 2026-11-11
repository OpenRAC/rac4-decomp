/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern char D_0019E650[];
extern void func_01EEDCD0(char *p, char *src, s32 n);

/* Seed the colour/limit words, copy the 0x40-byte template into the 0x38 block
   and let the object's own +0x5C entry initialise the rest. */
void func_01F0AA54(char *p)
{
    func_01EEDCD0(p + 0x38, D_0019E650, 0x40);
    *(s32 *)(p + 0x2C) = 0xFF00FF00;
    *(s32 *)(p + 0xB4) = 0xFF808080;
    *(s32 *)(p + 0x30) = -1;
    *(s32 *)(p + 0xB8) = -1;
    *(s32 *)(p + 0xC0) = 0;
    *(s32 *)(p + 0xDC) = 0;
    *(s32 *)(p + 0xE0) = 0;
    (*(void (**)(char *))((char *)*(void **)(p + 0xB0) + 0x5C))(p);
}
