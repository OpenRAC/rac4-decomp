/* cflags: @ee29 -O2 -G8 */
#include "common.h"

void func_004FAD28(void *); /* extern */
s32 func_L00_004FAAF0(void *, s32, s32, s32 *, s32); /* extern */
void func_L00_0051EB68(s32); /* extern */
void func_L00_005205F8(s32); /* extern */
extern s32 D_004AE4B8[];
void func_L00_00526210(void *arg0) {
    s32 value;
    if (arg0 == 0) return;
    value = func_L00_004FAAF0((u8 *)arg0 + 0x10, -1, 9, D_004AE4B8, 0xDB);
    if (value > 0) return;
    value = *(s32 *)((u8 *)arg0 + 0xC);
    if (value != 0) func_L00_0051EB68(value);
    value = *(s32 *)((u8 *)arg0 + 4);
    if (value != 0) func_L00_005205F8(value);
    value = *(s32 *)((u8 *)arg0 + 0x18);
    if (value != 0) func_004FAD28((void *)value);
    func_004FAD28(arg0);
}
