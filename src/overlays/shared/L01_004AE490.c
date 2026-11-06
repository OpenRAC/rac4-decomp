#include "common.h"
void func_L01_004AE490(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg0) + 0xB8));
    if ((temp_v0 != NULL) && ((*(u16 *)((u8 *)(temp_v0) + 0x34)) & 1)) {
        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41);
    }
}
