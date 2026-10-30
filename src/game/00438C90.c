#include "common.h"

extern void *D_003D6398[];
s32 func_00438D38(s32);

s32 func_00438C90(u32 arg0) {
    if (arg0 < 0x62U) {
        return func_00438D38((s32)D_003D6398[arg0]);
    }
    return -1;
}
