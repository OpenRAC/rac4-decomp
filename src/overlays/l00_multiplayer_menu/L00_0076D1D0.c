#include "common.h"

extern u32 func_L00_0076E5C0(const u8 *node);
extern void func_L00_0076D2A8(u8 *node, u32 kind);

void func_L00_0076D1D0(u8 *list, u8 *node)
{
    u32 kind = func_L00_0076E5C0(node);
    func_L00_0076D2A8(node, kind);
    *(u8 **)(node + 0xD4) = *(u8 **)(list + 8);
    *(u8 **)(list + 8) = node;
}
