/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern u8 D_001AF040[];
extern s32 D_001AF280[];
extern s32 D_00167C98[];
extern s32 D_00167CA4[];
extern s32 func_0013C2E8(s32 enabled);
extern void func_00129990(s32 command);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 sendSize,
                         void *receive, s32 receiveSize,
                         void (*complete)(void *), void *argument);

s32 func_0013B460(void)
{
    s32 result;

    if (D_00167C98[0] == 0) {
        return 1;
    }
    func_0013C2E8(0);
    D_001AF280[0] = 15;
    if (func_0012A718(D_001AF040, 1, 0, D_001AF280, 0x80,
                      D_001AF280, 0x80, 0, 0) < 0) {
        return 0;
    }
    func_00129990((s32)0x80000019u);
    result = D_001AF280[3];
    if (result == 1) {
        D_00167C98[0] = 0;
    }
    D_00167CA4[0] = 0;
    return result;
}
