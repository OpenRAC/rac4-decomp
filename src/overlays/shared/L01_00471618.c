#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_L00_005DD4A0(void *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

/* Update an object from its parent, dropping state when the parent is gone. */
void func_L01_00471618(u8 *arg0) {
    u8 *parent = *(u8 **)(arg0 + 0xB8);
    if (parent == 0 || parent[0x20] == 0xFE || parent[0x20] == 0xFD) {
        func_L01_00591BD8(arg0, 1, -1);
    }
    switch (arg0[0x20]) {
    case 0:
        *(u128 *)(arg0 + 0x10) = *(u128 *)(*(u8 **)(arg0 + 0xB8) + 0x10);
        break;
    case 1:
        func_L00_005DD4A0(arg0);
        break;
    }
}
