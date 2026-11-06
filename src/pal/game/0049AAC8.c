#include "common.h"
typedef struct {
    s32 unused, key;
} Key;
typedef struct {
    Key *key;
    void *object;
    u8 rest[12];
} Entry;
extern Entry D_002F3A50[];
extern s32 func_004A3AF0(void *, void *, void *);
extern void func_0049A270(Entry *);
void func_0049AAC8(s32 key)
{
    Entry *entry = D_002F3A50;
    Entry *end = (Entry *)((u32)entry + 0x280);
    for (; (s32)entry < (s32)end; entry++) {
        if (entry->key && entry->key->key == key) {
            func_004A3AF0(entry->object, NULL, NULL);
            func_0049A270(entry);
            break;
        }
    }
}
