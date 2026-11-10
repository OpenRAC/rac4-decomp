#include "common.h"
extern u32 *D_002214D8;
extern void *func_0048B818(u32, u8 **, const u8 *);
extern void func_00453718(void *, const void *, u32);
s32 func_0048C440(const u8 *input, u8 **cursor, const u8 *limit)
{
    u32 *state = D_002214D8;
    void *result;
    s32 count;
    u32 offset;
    if ((s32)state[0xC00] < 2) {
        result = func_0048B818(12, cursor, limit);
        D_002214D8[0xC0C] = (u32)result;
        if (!D_002214D8[0xC0C])
            return 1;
        D_002214D8[0xC0B] = 1;
        *(u16 *)D_002214D8[0xC0C] = 0;
        *(u16 *)(D_002214D8[0xC0C] + 2) = *(u16 *)((u8 *)D_002214D8 + 0x300C);
        *(u16 *)(D_002214D8[0xC0C] + 4) = 0;
        *(u16 *)(D_002214D8[0xC0C] + 6) = 0;
        *(u16 *)(D_002214D8[0xC0C] + 8) = 0;
        return 0;
    }
    func_00453718(&state[0xC0B], input, 4);
    input += 4;
    result = func_0048B818(D_002214D8[0xC0B] * 12, cursor, limit);
    D_002214D8[0xC0C] = (u32)result;
    if (!D_002214D8[0xC0C])
        return 1;
    count = 0;
    if (count >= (s32)D_002214D8[0xC0B])
        return 0;
    offset = 0;
    do {
        func_00453718((void *)(D_002214D8[0xC0C] + offset), input, 12);
        input += 12;
        offset += 12;
        ++count;
    } while (count < (s32)D_002214D8[0xC0B]);
    return 0;
}
