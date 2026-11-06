#include "common.h"
void *func_L00_004FACD8(s32);                   /* extern */

void *func_L00_00538190(void) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = func_L00_004FACD8(0x14);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        (*(s32 *)((u8 *)(temp_v0) + 4)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0x10)) = 1;
        (*(s32 *)((u8 *)(temp_v0) + 0xC)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 8)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0)) = 0;
        var_v0 = temp_v0;
    }
    return var_v0;
}
