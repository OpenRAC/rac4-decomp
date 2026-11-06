/* Reference: OpenRAC/rac2-decomp @ 99f35ac2c084fc59cdf3d631f8f960a825e7a49c; func_L00_0037DD18 (src/levels/shared/L00_0037B6F0.c).
 * Independently reconstructed and checked against RAC4 PAL retail. */
#include "common.h"

typedef struct {
    void *object;
    u32 key;
    s32 timer;
    u32 unknownC;
} Entry;

extern Entry D_00328548[32];

void func_004EA5F0(u32 key, void *object, s32 timer)
{
    s32 i = 0;
    Entry *entry;

    if (D_00328548[0].key == 0) {
        D_00328548[0].object = object;
        D_00328548[0].key = key;
        D_00328548[0].timer = timer;
        return;
    }
next:
    i++;
    if (i >= 32) {
        return;
    }
    if (D_00328548[i].key != 0) {
        goto next;
    }
    entry = &D_00328548[i];
    entry->key = key;
    entry->object = object;
    entry->timer = timer;
}
