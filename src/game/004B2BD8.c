#include "common.h"

/* Formats a time value (seconds) into the string buffer at arg0 + 8 as hours, minutes and seconds. */
extern void func_0011D920();
extern u8 D_003D1BF8[];

void func_004B2BD8(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = *arg0;
    func_0011D920((u8 *)arg0 + 8, D_003D1BF8, temp_v0 / 3600, (temp_v0 % 3600) / 60, temp_v0 % 60);
}
