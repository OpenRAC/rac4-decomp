/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern u8 D_00167B40[];
extern s32 D_001671C0[];
extern s32 D_00165FEC;
extern s32 func_00137558(s32 command);
extern s32 func_00126BC0(s32 semaphore);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 send_size, void *receive, s32 receive_size,
                         void (*complete)(void *), void *argument);
s32 func_00137FB0(void)
{
    s32 result;
    if (!func_00137558(3))
        return -1;
    if (func_0012A718(D_00167B40, 4, 0, 0, 0, D_001671C0, 4, 0, 0) < 0) {
        func_00126BC0(D_00165FEC);
        return -1;
    }
    result = *(s32 *)((u32)D_001671C0 | 0x20000000u);
    func_00126BC0(D_00165FEC);
    return result;
}
