#include "common.h"

extern void func_L05_004F41E8(void *);
extern s32 func_L05_004F4FB0(void *);
extern void func_00487920(void *);
extern void func_00449A28(void *, void (*)(void *), void *);
extern void func_L05_004F4FF0(void *);
extern void *D_0022299C;

/* Updates the object, then marks its state and queues its callback when it is not complete. */
void func_L05_004F4180(void *arg0) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0xAC);
    void (*cb)(void *);
    func_L05_004F41E8(arg0);
    if (func_L05_004F4FB0(arg0) == 0) {
        *(state + 0x85) = 2;
        func_00487920(arg0);
        cb = func_L05_004F4FF0;
        func_00449A28(&D_0022299C, cb, arg0);
    }
}
