#include "common.h"

typedef struct { s32 key; void *value; } Slot;
typedef struct { u8 pad[8]; Slot slot[8]; } Hash;
u8 D_0022338A = 0;

/* Looks key up in an 8-slot open-addressing table (key/value pairs at +8, probed from key & 7 with stride 0x13D573): its value, or null at an empty slot or after 8 probes. A value equal to &D_0022338A marks a removed slot and is skipped. */
void *func_L00_0069FE90(Hash *h, s32 key) {
    s32 n = 0;
    void *dead = &D_0022338A;
    u32 i = key & 7;
    for (; n < 8; n++) {
        u32 j = i & 7;
        void *v = h->slot[j].value;
        if (v == 0) {
            return 0;
        }
        if (h->slot[j].key == key && v != dead) {
            return v;
        }
        i += 0x13D573;
    }
    return 0;
}
