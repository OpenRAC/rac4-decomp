#include "common.h"

void func_00154930(s32, s32, s32, void *);
void func_00154BA8(void);
extern s32 func_00159C30[];

// Initializes something and returns 1
s32 func_00460288(void) {
    func_00154930(1, 0, 0x3B, func_00159C30);
    func_00154BA8();
    return 1;
}
