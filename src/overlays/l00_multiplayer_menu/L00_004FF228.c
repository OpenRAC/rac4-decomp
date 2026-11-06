/* cflags: @ee29 */
#include "common.h"
s32 func_0011A518();
s32 func_L00_004F84C8(s32, s32, s32, s32, s32); /* extern */
void *func_L00_004FACD8(s32);                   /* extern */

void *func_L00_004FF228(void) {
    void *temp_v0;

    temp_v0 = func_L00_004FACD8(0x70);
    if (temp_v0 == NULL) {
        func_L00_004F84C8(0x14, 0xA3, 0x21, 0, 0);
        return NULL;
    }
    func_0011A518(temp_v0, 0, 0x70);
    (*(void **)((u8 *)(temp_v0) + 4)) = (void *) (temp_v0 + 0x40);
    (*(s32 *)((u8 *)(temp_v0) + 0x6C)) = 1;
    return temp_v0;
}
