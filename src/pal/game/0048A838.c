#include "pal/event_state.h"

void func_0048A838(s32 event, s64 argument)
{
    PalEventState *entry = (PalEventState *)(s32)argument;

    if (entry != NULL) {
        if (event < 0) {
            entry->event = event;
        }
        if (event != 0) {
            if (entry->state == 9) {
                entry->state = 4;
                if (entry->notify != 0) {
                    D_002069FC[0] = 1;
                }
            }
        } else {
            entry->state = 0;
        }
    }
}
