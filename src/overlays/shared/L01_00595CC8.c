#include "common.h"
s32 func_L01_00595CC8(void *arg0) {
    void *temp_v1;

    if ((arg0 == NULL) || (temp_v1 = (*(void **)((u8 *)(arg0) + 0xAC)), (temp_v1 == NULL)) || !((*(u16 *)((u8 *)(arg0) + 0x34)) & 0x20)) {
        return 0;
    }
    return (*(s32 *)((u8 *)(temp_v1) + 0x18));
}
