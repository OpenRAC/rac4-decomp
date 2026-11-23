/* Not matching yet: PAL WIP; main net.text 0x01F03110, 92B. Not part of the build. */
/*
 *  0x0000 lw $a2, 0xB4($a0) | lw $a3, 0xB4($a0) 0x0004 daddu $a3, $zero, $zero | daddu $a2, $zero,
 * $zero 0x0008 blez $a2, . + 4 + (0x12 << 2) | blez $a3, . + 4 + (0x12 << 2) 0x001C addiu $a3,
 * $a3, 0x1 | addiu $a2, $a2, 0x1 0x0024 slt $v1, $a3, $a2 | slt $v1, $a2, $a3 0x002C add.s $f0,
 * $f0, $f1 | addiu $a1, $a1, 0x4 0x0030 addiu $a1, $a1, 0x4 | add.s $f0, $f0, $f1 0x0038 addu $v0,
 * $t0, $v0 | addu $v0, $v0, $t0 0x003C sw
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 46f174fa6e1de7993509ba80a4d799f83d490b6ec71d13b99ef2cf5f3d8a4b45
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01F03110 nonmatching/pal/net/func_01F03110.c --diff
 */
#include "common.h"

void func_01F03110(void *arg0)
{
    u8 *object = arg0;
    s32 count = *(s32 *)(object + 0xB4);
    s32 i = 0;

    *(f32 *)(object + 0x24) = 0.0f;
    if (count > 0) {
        u8 *records = *(u8 **)(object + 0xD0);
        s32 *cursor = *(s32 **)(object + 0xF0);

        do {
            f32 prior = *(f32 *)(object + 0x24);
            f32 base = *(f32 *)(object + 0x18);
            s32 index;
            u8 *record;
            f32 duration;

            i += 1;
            index = *cursor;
            cursor += 1;
            record = records + ((u32)index << 5);
            duration = *(f32 *)(record + 0x10);
            *(f32 *)(record + 0x14) = base + prior;
            *(f32 *)(object + 0x24) = *(f32 *)(object + 0x24) + duration;
        } while (i < count);
    }
}
