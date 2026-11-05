/* cflags: @ee29 -O2 -G0 */
#include "common.h"

void func_004FAD28(void *);
void func_L00_00537FB0(void *);

void func_L00_00538258(u8 *object) {
    s32 remaining = 0xB;
    u8 *entry = object + 4;
    do {
        func_L00_00537FB0(entry);
        remaining -= 1;
        entry += 0x14;
    } while (remaining >= 0);
    if (*(s32 *)(object + 0x108) & 1) func_004FAD28(object);
}
