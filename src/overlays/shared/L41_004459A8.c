#include "common.h"

extern s32 func_L41_00445DA0(s32, s32, s32, s32);
extern s32 D_222794;
extern s32 D_002227B0;

// Walks 0x100-byte records from D_222794 until one equals arg1 or the end value, then calls func_L41_00445DA0 for the matching index.
s32 func_L41_004459A8(s32 arg0, s32 arg1) {
    s32 ptr = D_222794;
    s32 result = 0;
    s32 count = 0;

    while (ptr != D_002227B0) {
        if (ptr == arg1) {
            result = func_L41_00445DA0(arg0, count, D_002227B0, arg1);
            break;
        }
        count++;
        ptr += 0x100;
    }
    return result;
}
