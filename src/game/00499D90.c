#include "common.h"
typedef struct {
    s32 unused, key;
} Key;
typedef struct {
    Key *key;
    void *object;
    u8 rest[12];
} Entry;
extern Entry D_002F3950[];
extern s32 func_004A2D90(void *, void *, void *);
extern void func_00499538(Entry *);
void func_00499D90(s32 key)
{
    Entry *entry = D_002F3950;
    Entry *end = (Entry *)((u32)entry + 0x280);
    for (; (s32)entry < (s32)end; entry++) {
        if (entry->key && entry->key->key == key) {
            func_004A2D90(entry->object, NULL, NULL);
            func_00499538(entry);
            break;
        }
    }
}
