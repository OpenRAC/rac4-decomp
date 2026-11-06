/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
void func_L00_00717C68();                        /* extern */
s32 func_L00_0071B478();                        /* extern */
s32 func_L00_0071BB58(void *);                  /* extern */
s32 func_L00_0071BC68(void *);                  /* extern */

void func_L00_00763C00(void *arg0) {
    func_L00_0071B478();
    func_L00_0071BC68(arg0);
    func_L00_0071BB58(arg0);
    *(s32 *)0x2213C8 = -1;
    (*(s32 *)((u8 *)(arg0) + 0x264)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x268)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x260)) = 0;
    func_L00_00717C68();
}
