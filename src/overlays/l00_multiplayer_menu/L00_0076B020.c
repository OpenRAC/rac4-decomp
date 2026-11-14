#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_1ED53A8(void *, void *, s32);
extern void func_0015CEF8();
extern u16 D_002217E0[];

typedef struct {
    u16 f0;
    u8 pad2[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} Type2;

/* Starts a request built from the object's state and reports failure. */
s32 func_L00_0076B020(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Type2 req;
    s32 ret = 1;
    s32 temp;

    if (arg0[0x4B8] != 0) {
        *(s32 *)(arg0 + 0x4B4) = arg2;
        *(s32 *)(arg0 + 0x4B0) = arg1;
        req.f0 = D_002217E0[0];
        temp = *(s32 *)(arg0 + 0x4CC);
        arg0[0x4C0] = 1;
        req.f18 = arg1;
        req.f1C = arg2;
        req.f24 = temp;
        req.f20 = arg3;
        *(s32 *)(arg0 + 0x4C4) = func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B548(func_1ED53A8(&req, func_0015CEF8, 0));
        if (func_0015B558() != 0) {
            ret = 0;
        }
    }
    return ret;
}
