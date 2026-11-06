#include "common.h"

typedef struct { s32 key; void *value; } Slot;
typedef struct { u8 pad[8]; Slot slot[3]; } Hash3;
u8 D_00223397 = 0;

/* Looks key up in a 3-slot open-addressing table (key/value pairs at +8, probed at (i + key % 3) % 3 with i growing by 0x13D573): its value, or null at an empty slot or after 3 probes. A value equal to &D_00223397 marks a removed slot and is skipped. */
void *func_L00_006A0460(Hash3 *h, u32 key) {
    s32 n = 0;
    u32 m = 3;
    void *dead = &D_00223397;
    u32 i = 0;
    for (; n < 3; n++) {
        u32 j = (i + key % m) % m;
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
