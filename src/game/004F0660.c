#include "common.h"

typedef struct Stream Stream;
typedef struct {
    u8 prefix[8];
    u8 *source;
    s32 size;
    u64 first, second;
} Block;
extern Stream *D_00221ED4;
extern char D_003D31D0[];
extern void func_004F1C10(Stream *, u8 **, s32 *, u8 **, s32 *);
extern s32 func_004F0848(u8 *, s32, u8 *, s32, const u8 *, s32, const u8 *, s32);
extern s32 func_004F1CB8(Stream *, u64, u64, const u8 *, s32);
extern void func_004EF6A0(const char *);
extern void func_004F1C30(Stream *, s32);
s32 func_004F0660(s32 unused, Block *block, const u8 *buffer)
{
    u8 *first, *second;
    s32 firstSize, secondSize;
    s32 offset = *(const s32 *)(buffer + 0x50008);
    const u8 *source = block->source;
    s32 size = block->size;
    s32 count = (s32)((u32)buffer + offset - (u32)source);
    s32 remaining;
    s32 copied;
    if (size < count)
        count = size;
    remaining = size - count;
    func_004F1C10(D_00221ED4, &first, &firstSize, &second, &secondSize);
    copied = func_004F0848((u8 *)(((u32)first & 0x0FFFFFFF) | 0x20000000), firstSize,
                           (u8 *)(((u32)second & 0x0FFFFFFF) | 0x20000000), secondSize, source, count, buffer, remaining);
    if (copied > 0) {
        if (!func_004F1CB8(D_00221ED4, block->first, block->second, first, copied))
            func_004EF6A0(D_003D31D0);
    }
    func_004F1C30(D_00221ED4, copied);
    return copied > 0;
}
