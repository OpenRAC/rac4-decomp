/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_01EBD390(char *, s32 *);

/* Finds the first 0x50-byte entry of the table at 0x184 whose first word is
   clear, releases it, and returns its index; 0xFFFE when there is none. */
s32 func_01EB9918(char *p)
{
    u16 i;
    s32 *entry;

    if (p == 0) {
        return 0xFFFE;
    }
    entry = *(s32 **)(p + 0x184);
    for (i = 0; i < *(u16 *)(p + 0x19C); i++) {
        if (entry[0] == 0) {
            func_01EBD390(p, entry);
            return i;
        }
        entry = (s32 *)((char *)entry + 0x50);
    }
    return 0xFFFE;
}
