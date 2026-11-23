#include "common.h"

extern s32 func_0047D4E8(void);

f32 func_L01_005A9CA0(void *object)
{
    s32 context;
    void **slots;
    void *slot;
    u8 *payload;
    void *metadata;
    s32 i;
    u8 state;

    context = func_0047D4E8();
    if (object != NULL) {
        if ((*(u8 *)((u8 *)object + 0xBE) & 4) ||
            ((state = *(u8 *)((u8 *)object + 0x20)) == 0xFE) ||
            ((slots = (void **)((u8 *)context + 0x1D0)), state == 0xFD)) {
            return 1.0f;
        }
        goto search;

matched:
        return 1.0f - (f32)*(s16 *)(payload + 0x6AE) / (f32)*(s16 *)(payload + 0x6B0);

search:
        i = 0;
        do {
            slot = *slots;
            if (slot != NULL) {
                payload = *(u8 **)((u8 *)slot + 0xAC);
                metadata = *(void **)(payload + 0x6BC);
                if (metadata != NULL && *(s32 *)metadata == 2) {
                    if (*(void **)((u8 *)metadata + 4) == object) {
                            goto matched;
                    }
                }
            }
            i++;
            slots++;
        } while (i < 4);
    }
    return 0.0f;
}
