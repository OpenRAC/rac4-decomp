#include "common.h"

/* Applies indexed flag changes to each entry in the sentinel-terminated group table. */
typedef struct {
    u32 flags;
    char pad[0x1F];
    u8 index;
    char pad24[0xC];
    u32 other;
    char tail[0x1C];
} Entry;
typedef struct {
    Entry *entries;
    s32 count;
} Group;
typedef struct {
    s16 flags, other;
} Change;
extern Group D_00324080[];
extern Change D_00323D80[];
void func_004E2E30(void)
{
    Group *g = D_00324080;
    while (g->entries) {
        Entry *p = g->entries;
        if (g->count > 0) {
            s32 count = g->count;
            do {
                Change *c = &D_00323D80[p->index];
                if (c->flags)
                    p->flags = (p->flags & 0xFFFFC000) | c->flags;
                if (c->other)
                    p->other = (p->other & 0xFFFFC000) | c->other;
                p++;
                count--;
            } while (count != 0);
        }
        g++;
    }
}
