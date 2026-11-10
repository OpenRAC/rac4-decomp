#include "common.h"

typedef int Quad __attribute__((mode(TI)));
extern u8 *D_00221F20;
extern Quad D_00220000;
void func_0044AA58(const u64 *coordinates, const s32 *values)
{
    u8 *first, *next, *cursor;
    *(u32 *)(D_00221F20 + 0) = 0x10000005;
    *(u32 *)(D_00221F20 + 4) = 0;
    *(u32 *)(D_00221F20 + 8) = 0;
    *(u32 *)(D_00221F20 + 12) = 0x50000005;
    cursor = (u8 *)D_00221F20;
    D_00221F20 = cursor + 16;
    *(Quad *)(cursor + 16) = D_00220000;
    first = (u8 *)D_00221F20;
    next = first + 16;
    D_00221F20 = next;
    *(u64 *)(first + 16) = 0x4C;
    *(u64 *)(next + 8) = (s64)values[0];
    *(u64 *)(next + 16) = coordinates[0];
    *(u64 *)(next + 24) = coordinates[2];
    *(u64 *)(next + 32) = (s64)values[1];
    *(u64 *)(next + 40) = coordinates[1];
    *(u64 *)(next + 48) = coordinates[3];
    *(u64 *)(next + 56) = 0;
    D_00221F20 += 64;
}
