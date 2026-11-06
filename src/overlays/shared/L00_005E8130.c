#include "common.h"

typedef struct Child {
    u8 unknown0[8];
    u32 flag;
} Child;

typedef struct Parent {
    u8 unknown0[0x98];
    Child *child;
} Parent;

s32 func_L00_005E8130(const Parent *parent)
{
    if (parent->child != NULL) {
        if (parent->child->flag != 0) {
            return 1;
        }
    }
    return 0;
}
