#include "common.h"

typedef struct Type1 {
    s32 f0, f4;
    u32 f8[2048];
} Type1;
u8 D_00222110 = 0;

/* Remove a key from the open-addressed table and return its stored pointer. */
void *func_00500C20(Type1 *table, u32 key)
{
    char *values = (char *)table + 0xC;
    char *keys = (char *)table + 8;
    s32 attempts = 0;
    u32 probe = key & 0x3FF;
    do {
        s32 offset = (probe & 0x3FF) * 8;
        void **slot = (void **)(values + offset);
        void *current = *slot;
        if (!current)
            return 0;
        if (current != &D_00222110) {
            if (*(u32 *)(keys + offset) == key) {
                *slot = &D_00222110;
                table->f4--;
                return current;
            }
        }
        attempts++;
        probe += 0x13D573;
    } while (attempts < 0x400);
    return 0;
}
