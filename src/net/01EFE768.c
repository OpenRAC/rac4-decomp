/* cflags: @ee296 -Os -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"
extern void func_0011A518(void *, s32, s32);
extern void *func_01EEDCD0(void *, const void *, s32);
extern void func_01EFEB30(void *);
extern char D_0019D9D8[];

void func_01EFE768(u8 *p) {
    func_01EEDCD0(p + 0x38, D_0019D9D8, 0x40);
    func_0011A518(p + 0xD0, 0, 0x100);
    func_0011A518(p + 0x1D0, 0, 0x100);
    func_0011A518(p + 0x2E4, 0, 0x6100);
    func_0011A518(p + 0x63E4, 0, 0x100);
    func_0011A518(p + 0x64E4, 0, 0x100);
    func_0011A518(p + 0x65E4, 0, 0x100);
    func_0011A518(p + 0x66E8, 0, 0x100);
    func_0011A518(p + 0x67E8, 0, 0x100);
    func_0011A518(p + 0x68E8, 0, 0x100);
    *(s32 *)(p + 0x66E4) = 0;
    *(s32 *)(p + 0xB4) = 0;
    *(s32 *)(p + 0x2DC) = 1;
    *(s32 *)(p + 0xB8) = 0;
    *(s32 *)(p + 0xBC) = 0;
    *(s32 *)(p + 0xC0) = 0;
    *(s32 *)(p + 0xC4) = 0;
    *(s32 *)(p + 0xC8) = 0;
    *(s32 *)(p + 0xCC) = 0;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x8) = 0;
    *(s32 *)(p + 0x2D0) = 0;
    *(s32 *)(p + 0x2D4) = 0;
    *(s32 *)(p + 0x2D8) = 0;
    *(s32 *)(p + 0x2E0) = 0;
    *(s32 *)(p + 0x69E8) = 0;
    func_01EFEB30(p);
}
