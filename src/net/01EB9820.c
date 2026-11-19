/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad[0x44];
} Entry;

s32 func_01EB9820(char *p, s32 target)
{
    u16 i;
    Entry *entry;

    i = 0;
    if (*(u16 *)(p + 0x19C) != 0) {
        entry = *(Entry **)(p + 0x184);
        do {
            if (target == entry[i].unk4) {
                return i;
            }
            if (target == entry[i].unk8) {
                return i;
            }
            i++;
        } while (i < *(u16 *)(p + 0x19C));
    }
    return 0xFFFE;
}
