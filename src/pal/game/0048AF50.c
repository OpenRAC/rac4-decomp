/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division -ffast-math */
#include "common.h"

typedef struct AudioEntry {
    s32 handle;
    u16 id;
    u8 kind;
    u8 flags;
    u8 state;
    u8 previous;
    u8 pad0A[0xE];
    u32 userdata;
    s32 unknown1C;
    f32 gain;
    f32 envelope;
    f32 remaining;
    f32 rate;
    u8 pad30[0x20];
} AudioEntry;

typedef void (*AudioCallback)(s32 result, u64 userdata);
extern AudioEntry D_00355DC0[];
extern s32 func_0048B4E8(void *manager, AudioEntry *entry);
extern void func_0048B408(AudioEntry *entry);
extern void func_0048B720(void *manager, AudioEntry *entry);
extern void func_0048B700(void *manager, AudioEntry *entry);
extern void func_0048B9E8(s32 result, u64 userdata);
extern void func_0048BA50(s32 result, u64 userdata);
extern void func_001593A8(s32 handle, AudioCallback callback, u64 userdata);
extern void func_00158930(s32 handle, AudioCallback callback, u64 userdata);
extern void func_001592E8(s32 handle);
extern void func_001587F0(s32 handle);
extern void func_00159318(s32 handle);

void func_0048AF50(void *manager, f32 delta)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        AudioEntry *entry = D_00355DC0 + i;
        if (entry->state == 1) {
            if ((entry->flags & 8) || !func_0048B4E8(manager, entry)) {
                func_0048B408(entry);
                continue;
            }
            entry->state = 2;
        }
        if (entry->state == 2 && (entry->flags & 8)) {
            func_0048B408(entry);
            continue;
        }
        if (entry->state == 3) {
            if (entry->flags & 8) {
                entry->state = 7;
                entry->flags &= ~8;
            } else {
                func_001593A8(entry->handle, func_0048B9E8, entry->userdata);
            }
        }
        if (entry->state == 4) {
            if (entry->flags & 8) {
                entry->state = 7;
                entry->flags &= ~8;
            } else if (entry->flags & 2) {
                entry->previous = entry->state;
                entry->flags &= ~2;
                entry->state = 6;
            } else if (entry->flags & 1) {
                func_0048B720(manager, entry);
                func_0048B700(manager, entry);
                entry->state = 5;
                entry->flags &= ~1;
            }
        }
        if (entry->state == 5) {
            if (entry->flags & 8) {
                entry->state = 7;
                entry->flags &= ~8;
            } else if (entry->flags & 2) {
                func_001592E8(entry->handle);
                entry->previous = entry->state;
                entry->state = 6;
                entry->flags &= ~2;
            } else {
                func_0048B720(manager, entry);
            }
            func_00158930(entry->handle, func_0048BA50, entry->userdata);
        }
        if (entry->state == 7) {
            if (entry->remaining > 0.0f) {
                f32 remaining = entry->remaining - delta;
                remaining = remaining > 0.0f ? remaining : 0.0f;
                entry->remaining = remaining;
                entry->envelope = remaining * entry->rate;
                func_0048B720(manager, entry);
            } else {
                func_001587F0(entry->handle);
            }
            func_00158930(entry->handle, func_0048BA50, entry->userdata);
        }
        if (entry->state == 6) {
            if (entry->flags & 8) {
                entry->state = 7;
                entry->flags &= ~8;
            } else if (entry->flags & 4) {
                if (entry->previous == 5)
                    func_00159318(entry->handle);
                entry->state = entry->previous;
                entry->flags &= ~4;
            }
        }
    }
}
