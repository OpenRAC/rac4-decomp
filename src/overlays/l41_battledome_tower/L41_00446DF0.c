#include "common.h"

extern void func_00611808(void *, s32 *, s32);
extern void *func_L01_006B4FC0(s32, s32, s32, s32);

// Message writer: opens a stream with func_L01_006B4FC0 (kind 2) and writes two
// words.
void func_L41_00446DF0(s32 target, s32 value_a, s32 value_b) {
    s32 first;
    s32 second;
    void *stream = func_L01_006B4FC0(target, 2, 0, 0xFA);
    if (stream) {
        first = value_a;
        func_00611808(stream, &first, 4);
        second = value_b;
        func_00611808(stream, &second, 4);
    }
}
