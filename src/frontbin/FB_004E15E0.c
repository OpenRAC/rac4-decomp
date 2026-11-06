/* cflags: -Wuninitialized */
#include "common.h"

typedef struct {
    u32 first;
    u8 gap[44];
    u32 saved;
    u32 clear;
} GlobalView;
extern GlobalView D_001DFA70;

typedef struct {
    u32 first;
    u32 second;
    u8 tail[8];
} Record;
extern Record D_00323480[];

s32 func_FB_004E15E0(void) {
    Record *record = D_00323480;
    s32 count = 63;

    D_001DFA70.clear = 0;
    D_001DFA70.saved = D_001DFA70.first;
    do {
        record->first = 0;
        count--;
        record->second = 0;
        record++;
    } while (count >= 0);
    return count;
}
