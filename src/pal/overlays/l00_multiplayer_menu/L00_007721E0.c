#include "common.h"

extern u32 func_L00_007735D0(const u8 *node);
extern void func_L00_007722B8(u8 *node, u32 kind);

void func_L00_007721E0(u8 *list, u8 *node)
{
    u32 kind = func_L00_007735D0(node);
    func_L00_007722B8(node, kind);
    *(u8 **)(node + 0xD4) = *(u8 **)(list + 8);
    *(u8 **)(list + 8) = node;
}
