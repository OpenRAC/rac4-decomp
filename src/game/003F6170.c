#include "common.h"

extern u64 D_003CA120_[];
#define D_003CA120 (D_003CA120_[0])

void func_003F6170(s64 arg0) {
    D_003CA120 = (u64) (arg0 << 0x20) >> 0x20;
}
