#include "common.h"

typedef struct {
    u64 *words;
    s32 count;
} WordSequence;

s32 func_L00_00538C70(WordSequence *left, WordSequence *right) {
    s32 count = left->count;
    s32 i = (s32)((u32)count - (u32)right->count);
    u64 *a;
    u64 *b;
    if (i != 0) return i;
    a = left->words;
    b = right->words;
    for (i = (s32)((u32)count - 1U); i >= 0; i--) {
        if (a[i] != b[i]) {
            return a[i] > b[i] ? 1 : -1;
        }
    }
    return 0;
}
