#include "common.h"

s32 func_L00_007142A8(void *object, s32 index) {
    if (index < *(s32 *)((u8 *)object + 0x85C)) {
        return (s32)((u8 *)object + ((index << 8) + 0x860));
    }
    return 0;
}
