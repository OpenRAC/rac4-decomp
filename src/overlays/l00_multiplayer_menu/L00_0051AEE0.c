/* cflags: @ee29 -O2 -G8 */
#include "common.h"

s32 func_0011A518(void *, s32, s32);
void func_004FAD28(void *);
void func_L00_0051A7B8(s32);

void func_L00_0051AEE0(u8 *object) {
    s32 value = *(s32 *)(object + 4);
    if (value != 0) func_L00_0051A7B8(value);
    value = *(s32 *)(object + 8);
    if (value != 0) func_L00_0051A7B8(value);
    value = *(s32 *)(object + 0xC);
    if (value != 0) func_L00_0051A7B8(value);
    func_0011A518(object, 0, 0x58);
    return func_004FAD28(object);
}
