/* Not matching yet: BYTES 111/176 (tools/try_func.py func_01EBA5D0 --diff). Not part of the build. */
#include "common.h"

typedef struct __attribute__((packed)) {
    u8 a[2];
    u8 b;
    u8 d;
} Packet;

typedef struct {
    char pad[0x184];
    s32 f184;
    void *entries;
    char pad2[0x1C];
    u16 f1A4;
} Owner;

typedef struct {
    s32 *table;
    char pad[0xC];
    s32 f10;
} Entry;

s32 func_01EBC2E8(void *, u16, void *);

s32 func_01EBA5D0(Owner *arg0, u16 arg1, Packet *arg2) {
    Packet packet = *arg2;
    s32 result = 2;
    if (arg0 != NULL) {
        char *entries = arg0->entries;
        result = 0;
        if (entries != NULL) {
            u16 idx = arg0->f1A4;
            Entry *entry = (Entry *)(entries + packet.b * 0x18);
            if (entry->table[idx] != 0) {
                s32 *slot = &entry->table[arg1];
                if (*slot == 0) {
                    *slot = arg0->f184 + (arg1 * 0x50);
                    entry->f10++;
                    result = func_01EBC2E8(entry, idx, entry);
                }
            }
        }
    }
    return result;
}
