/* cflags: -O2 -G8 */
#include "common.h"

typedef struct {
    s32 id;
    s32 stamp;
} Entry;

extern Entry D_004AB6D0[];
extern s32 D_001721E0[];

void func_L00_00584FF8(s32 id)
{
    Entry *entry;
    s32 index;

    for (index = 0, entry = D_004AB6D0; index < 8; ++index, ++entry) {
        if (entry->id == id && (s32)((u32)D_001721E0[0x218 / sizeof(s32)] - 2000U) < entry->stamp) {
            entry->id = -1;
            return;
        }
    }
}
