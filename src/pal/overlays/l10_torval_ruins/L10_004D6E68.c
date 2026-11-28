#include "common.h"
#include "pal/object_callback.h"

extern PalObjectCallbackNode *D_L10_00222718;
extern void func_L10_004D6730(void *object);

typedef struct {
    u8 pad[0x450];
    u8 timer;
    u8 pad451;
    u8 remaining[2];
} TorvalMobyTimers;

void func_L10_004D6E68(void *moby, u8 *state) {
    TorvalMobyTimers *timers = (TorvalMobyTimers *)state;
    u8 count;
    u8 *end;
    void *obj;

    count = timers->timer;
    if (count != 0) {
        end = timers->remaining + 2;
        timers->timer = count - 1;
        state = timers->remaining;
        do {
            if (*state != 0) {
                *state -= 1;
            }
            state += 1;
        } while ((s32)state < (s32)end);
    }
    obj = moby;
    func_00449A28(&D_L10_00222718, func_L10_004D6730, obj);
}
