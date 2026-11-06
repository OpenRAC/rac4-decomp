
#include "common.h"

typedef struct {
    s32 event;
    u8 pad04[6];
    s16 state;
    u8 pad0C[4];
    s16 notify;
} EventState;

extern s16 D_00206974[];


void func_00489D30(s32 event, s64 argument)
{
    EventState *entry = (EventState *)(s32)argument;

    if (entry != NULL) {
        entry->event = event;
        if (event != 0) {
            if (entry->state == 1) {
                entry->state = 4;
                if (entry->notify != 0) {
                    D_00206974[0] = 1;
                }
            }
        } else {
            entry->state = 0;
        }
    }
}
