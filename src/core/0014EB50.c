/* cflags: -fno-opt-stack */
#include "common.h"

extern void func_00147AE0(void *arg0);
extern void func_00147AF0(void *arg0);
extern void func_00148800(struct Type1 *arg0, struct Type0 *arg1, struct Type2 *arg2);
extern void func_0014B808(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5);
extern void func_0014DFF0(s32 arg0, s32 arg1, void *arg2);
extern s32 D_0016F750[];

// Checks the two argument blocks, then runs the setup calls on the object and returns 0.
s32 func_0014EB50(u8 *arg0, u8 *arg1) {
    u8 sp[0x50];
    u8 sp50[0x50];

    if (arg1 == NULL) {
        return 0x181A;
    }
    if (*(s32 *)(arg1 + 0x8) == 0) {
        return 0x17F2;
    }
    if (*(s32 *)(arg1 + 0x0) == 0) {
        return 0x17ED;
    }
    if (!(*(u16 *)(arg1 + 0xE) < *(u16 *)(arg1 + 0xC))) {
        return 0x1801;
    }
    if (!(*(u16 *)(arg1 + 0x12) < *(u16 *)(arg1 + 0xC))) {
        return 0x1806;
    }
    if (!(*(u8 *)(arg1 + 0x10) < 8U)) {
        return 0x17F7;
    }
    if (!(*(u8 *)(arg1 + 0x14) < 8U)) {
        return 0x17FC;
    }
    if (arg0 == NULL) {
        return 0x17D4;
    }
    if (*(s64 *)arg0 != 0xFACE) {
        return 0x17D4;
    }
    if (arg0[0x18] != 0xA) {
        return 0x17DE;
    }
    if (D_0016F750[0] == 3) {
        func_00147AE0(arg0);
    }
    func_0014DFF0(*(s32 *)(arg1 + 0x0), *(s32 *)(arg0 + 0x1C), sp);
    func_00148800((struct Type1 *)sp50, (struct Type0 *)*(s32 *)(arg0 + 0x1C), (struct Type2 *)sp);
    func_0014B808(sp50, *(s32 *)(arg1 + 0x8), (s32)(arg1 + 0x12), (s32)(arg1 + 0x14), *(u16 *)(arg1 + 0xC), 0);
    if (D_0016F750[0] == 3) {
        func_00147AF0(arg0);
    }
    return 0;
}
