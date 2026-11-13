#include "common.h"

extern u8 D_00172434[];
extern s32 func_0015DA28(void);
extern void func_01ED5D68(void);
extern void func_L00_0077A178(void *);

s32 func_L00_00774A98(void *arg0) {
    void *a0;

    D_00172434[0] = 0;
    a0 = *(void **)((u8 *)arg0 + 0x64);
    if (*(u8 *)((u8 *)a0 + 0x11E) != 0) {
        func_L00_0077A178(a0);
    }
    func_01ED5D68();
    func_0015DA28();
    return 1;
}
