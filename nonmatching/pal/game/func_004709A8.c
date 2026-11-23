/* Not matching yet: PAL WIP; main .text 0x004709A8, 40B. Not part of the build. */
/*
 *  0x0000 lw $v0, 0x3C($a0) | lwu $t0, 0x3C($a0) 0x0004 andi $a0, $v0, 0xFF | srl $t2, $t0, 8
 * 0x0008 srl $v1, $v0, 8 | andi $t1, $t0, 0xFF 0x000C sw $a0, 0x0($a1) | srl $t3, $t0, 16 0x0010
 * andi $v1, $v1, 0xFF | sw $t1, 0x0($a1) 0x0014 srl $v0, $v0, 16 | andi $t2, $t2, 0xFF 0x0018 sw
 * $v1, 0x0($a2) | sw $t2, 0x0($a2) 0x001C andi $v0, $v0, 0xFF | andi $t3, $t3, 0xFF 0x0024 sw $v0,
 * 0x0($a3) | sw $t3, 0x0($a3)
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 1fba38b8baf8194537669b275128ad333bed7e28232549f73f4d7e95c57a5f91
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004709A8 nonmatching/pal/game/func_004709A8.c --diff
 */
#include "common.h"

void func_004709A8(void *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
  u32 packed;
  u32 low;
  u32 mid;
  u32 high;

  packed = *(u32 *)((u8 *)arg0 + 0x3C);
  low = packed & 0xFF;
  mid = (packed >> 8) & 0xFF;
  high = (packed >> 16) & 0xFF;
  *arg1 = low;
  *arg2 = mid;
  *arg3 = high;
}
