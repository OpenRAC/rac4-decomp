/* cflags: -fno-schedule-insns */
#include "common.h"
void *func_L00_004F86B0();                          /* extern */

void func_L00_00519EC8(void) {
    void *temp_v0;

    temp_v0 = func_L00_004F86B0();
    (*(s32 *)((u8 *)(temp_v0) + 0x188)) = 0;
    (*(s32 *)((u8 *)(temp_v0) + 0x18C)) = 0;
}
