#include "common.h"

typedef struct Video {
    u8 *pixels;
    u8 *packets;
    u8 p8[8];
    s32 count;
} Video;
extern Video *D_00221EA8;
extern const char D_003D3248[], D_003D3230[];
extern void func_004EF3E0(void);
extern void *func_004F2360(Video *);
extern s32 func_00142150(void *, const void *, u32);
extern void func_004EF6A0(const char *);
extern void func_004F0228(void *, u32, s32, s32, s32);
extern void func_004F22F0(Video *);
extern s32 func_00142220(void *);
extern s32 func_004F1CA0(void *);
extern s32 func_0011D5D8(const char *, ...);
extern s32 func_001421A0(void *);
s32 func_004F1EA0(void *task)
{
    s32 result = 1;
    void *block;
    s32 i;
    s32 width, height;
    Video *current;
    while (!func_00142220(task)) {
        if (func_004F1CA0(task) == 1) {
            result = -1;
            func_0011D5D8(D_003D3230);
            break;
        }
        while ((block = func_004F2360(D_00221EA8)) == NULL) {
            func_004EF3E0();
        }
        if (func_00142150(task, block, 0x340) < 0)
            func_004EF6A0(D_003D3248);
        if (*(s32 *)((u32)task + 8) == 0) {
            width = *(s32 *)task;
            height = *(s32 *)((u32)task + 4);
            i = 0;
            current = D_00221EA8;
            if (i < current->count) {
                do {
                    func_004F0228(current->packets + (u32)i * 0x27E40 + 0x40,
                                  (u32)current->pixels + (u32)i * 0xD0000, 0, width, height);
                    func_004F0228(D_00221EA8->packets + (u32)i * 0x27E40 + 0x13F40,
                                  (u32)D_00221EA8->pixels + (u32)i * 0xD0000, 1, width, height);
                    ++i;
                    current = D_00221EA8;
                } while (i < current->count);
            }
        }
        func_004F22F0(D_00221EA8);
        func_004EF3E0();
    }
    func_001421A0(task);
    return result;
}
