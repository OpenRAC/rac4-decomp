#include "common.h"
/*
 * Acquisition/tile-loop C structure adapted from the OpenRAC RAC3
 * decompilation contributors' func_003AD288 (GPL version 3):
 * games/rac3/ntsc/src/frontbin/3ABA48.c, commit
 * 73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde.
 * PAL addresses, interfaces and data layout verified against RAC4 retail.
 * See LICENSE and THIRD_PARTY_NOTICES.md.
 */
typedef struct Video {
    u8 *pixels;
    u8 *packets;
    u8 p8[8];
    s32 count;
} Video;
extern Video *D_00221FA8;
extern const char D_003D3288[], D_003D3270[];
extern void func_004F0448(void);
extern void *func_004F33C8(Video *);
extern s32 func_00142150(void *, const void *, u32);
extern void func_004F0708(const char *);
extern void func_004F1290(void *, u32, s32, s32, s32);
extern void func_004F3358(Video *);
extern s32 func_00142220(void *);
extern s32 func_004F2D08(void *);
extern s32 func_0011D5D8(const char *, ...);
extern s32 func_001421A0(void *);
s32 func_004F2F08(void *task)
{
    s32 result = 1;
    void *block;
    s32 i;
    s32 width, height;
    Video *current;
    while (!func_00142220(task)) {
        if (func_004F2D08(task) == 1) {
            result = -1;
            func_0011D5D8(D_003D3270);
            break;
        }
        while ((block = func_004F33C8(D_00221FA8)) == NULL) {
            func_004F0448();
        }
        if (func_00142150(task, block, 0x340) < 0)
            func_004F0708(D_003D3288);
        if (*(s32 *)((u32)task + 8) == 0) {
            width = *(s32 *)task;
            height = *(s32 *)((u32)task + 4);
            i = 0;
            current = D_00221FA8;
            if (i < current->count) {
                do {
                    func_004F1290(current->packets + (u32)i * 0x27E40 + 0x40,
                                  (u32)current->pixels + (u32)i * 0xD0000, 0, width, height);
                    func_004F1290(D_00221FA8->packets + (u32)i * 0x27E40 + 0x13F40,
                                  (u32)D_00221FA8->pixels + (u32)i * 0xD0000, 1, width, height);
                    ++i;
                    current = D_00221FA8;
                } while (i < current->count);
            }
        }
        func_004F3358(D_00221FA8);
        func_004F0448();
    }
    func_001421A0(task);
    return result;
}
