#include "common.h"

s32 func_L01_00482F60(void *p) {
    return (*(u8*)((u8*)p + 0xB) & 0x80) && (*(u16*)((u8*)p + 0x20) == 0);
}
