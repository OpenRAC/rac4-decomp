#include "common.h"

typedef struct {
    u8 pad0[0xE];
    s16 fE;
    u8 pad10[0x44];
    s32 f54;
} Type1;

extern s32 func_0011BF88(s32, s32);

void func_0011DB90(Type1 *arg0) {
    func_0011BF88(arg0->f54, arg0->fE);
}
