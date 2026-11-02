#include "common.h"

void *func_L01_006B4FC0(void *, s32, s32, s32);

// Open a stream with func_L01_006B4FC0 (kind 1, 0xFA) and discard it.
void func_L41_003D4E88(void *object) {
    func_L01_006B4FC0(object, 1, 0, 0xFA);
}
