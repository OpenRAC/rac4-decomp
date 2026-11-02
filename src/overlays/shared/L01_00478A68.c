/* cflags: -O2 -G8 */
#include "common.h"

typedef struct {
    s32 id;
    s32 stamp;
} Entry;

extern Entry D_003A9C78[];
extern s32 D_00172160[];

void func_L01_00478A68(s32 id)
{
    Entry *entry;
    s32 index;

    for (index = 0, entry = D_003A9C78; index < 8; ++index, ++entry) {
        if (entry->id == id && (s32)((u32)D_00172160[0x218 / sizeof(s32)] - 2000U) < entry->stamp) {
            entry->id = -1;
            return;
        }
    }
}
