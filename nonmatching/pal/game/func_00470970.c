/* Not matching yet: PAL WIP; main .text 0x00470970, 32B. Not part of the build. */
/*
 *  0x0008 or $a1, $a1, $a2 | dsll $t0, $t0, 16 0x000C dsll $t0, $t0, 16 | or $v0, $a1, $a2 0x0010
 * or $a1, $a1, $a3 | or $v0, $v0, $a3 0x0014 or $a1, $a1, $t0 | or $v0, $v0, $t0 0x001C sd $a1,
 * 0x38($a0) | sd $v0, 0x38($a0)
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: be5de065ef1c4abbe02ac64fb6eaa049a735be23bb8e7ee310888972e594b421
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00470970 nonmatching/pal/game/func_00470970.c --diff
 */
#include "common.h"

/* Assemble the full-width inputs and write the object field once. */
void func_00470970(void *object, u32 high, u64 low, u64 byte1, u64 byte2)
{
    *(u64 *)((u8 *)object + 0x38) =
        ((u64)high << 32) | low | (byte1 << 8) | (byte2 << 16);
}
