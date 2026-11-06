/* cflags: @ee29 */
#include "common.h"
s32 func_0011A518();
void *func_L00_004FACD8(s32);                   /* extern */

void *func_L00_005205A8(void) {
    void *temp_v0;

    temp_v0 = func_L00_004FACD8(0x18);
    if (temp_v0 == NULL) {
        return NULL;
    }
    func_0011A518(temp_v0, 0, 0x18);
    (*(s32 *)((u8 *)(temp_v0) + 0x14)) = 1;
    return temp_v0;
}
