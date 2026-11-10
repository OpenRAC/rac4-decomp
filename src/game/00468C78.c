#include "common.h"

typedef struct {
    u8 *data;
    s32 size;
    s32 type;
    s32 reserved;
} Block;
extern void func_00453608(void *, s32, s32);
extern void func_00453718(void *, const void *, s32);
extern u16 func_00468BE0(const void *, s32);
s32 func_00468C78(u8 *destination, s32 index, const Block *blocks)
{
    s32 size = 0;
    u8 *out = destination + 8;
    const Block *block;
    s32 offset;
    const u8 *data;
    if (blocks->data != 0) {
        block = blocks;
        do {
            size += 8;
            offset = index * block->size;
            data = block->data + offset;
            *(s32 *)out = block->type;
            *(s32 *)(out + 4) = block->size;
            out += 8;
            if (block->type == 0x1770) {
                func_00453608(out, 0, block->size);
            } else {
                func_00453718(out, data, block->size);
            }
            out += block->size;
            size += block->size;
            block++;
            out = (u8 *)(((s32)out + 3) & ~3);
            size = (size + 3) & ~3;
        } while (block->data != 0);
    }
    size += 8;
    *(s32 *)(out + 4) = 0;
    *(s32 *)out = -1;
    *(u32 *)(destination + 4) = func_00468BE0(destination + 8, size);
    *(s32 *)destination = size;
    return size + 8;
}
