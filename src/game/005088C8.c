#include "common.h"
typedef s32 (*Callback)(f32, f32, void *);
typedef struct {
    u32 key;
    Callback value;
} Entry;
typedef struct {
    s32 pad;
    s32 count;
    Entry entries[8];
} Table;
u8 D_00222115 = 0;
extern Callback func_00507B00(Table *, u32);
s32 func_005088C8(Table *a, u32 b, Callback c)
{
    if (a->count < 8 && !func_00507B00(a, b)) {
        s32 i = 0;
        char *values = (char *)a + 12;
        Callback sentinel = (Callback)&D_00222115;
        char *keys = (char *)a + 8;
        u32 probe = b & 7;
        for (; i < 8; i++, probe += 0x13D573) {
            u32 offset = (probe & 7) * 8;
            Callback *slot = (Callback *)(values + offset);
            if (!*slot || *slot == sentinel) {
                *slot = c;
                *(u32 *)(keys + offset) = b;
                a->count++;
                return 1;
            }
        }
    }
    return 0;
}
