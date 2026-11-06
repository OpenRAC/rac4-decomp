#include "common.h"
void *func_L00_006F0C48();                          /* extern */

s32 func_L01_005864A0(void) {
    void *temp_v0;

    temp_v0 = func_L00_006F0C48();
    if (temp_v0 != NULL) {
        return (*(s32 *)((u8 *)(temp_v0) + 4));
    }
    return 0;
}
