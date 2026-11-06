/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern u8 D_00167210[];
extern s32 D_001660C0[];
extern s32 D_00166068;
extern s32 func_00137258(s32 command);
extern s32 func_00126BC0(s32 semaphore);
extern s32 func_0012A718(void *client, s32 command, u32 mode,
                         const void *send, s32 send_size, void *receive, s32 receive_size,
                         void (*complete)(void *), void *argument);
s32 func_001373B0(void)
{
    s32 result;
    if (!func_00137258(2))
        return 0;
    if (func_0012A718(D_00167210, 14, 0, 0, 0, D_001660C0, 4, 0, 0) < 0) {
        func_00126BC0(D_00166068);
        return 0;
    }
    result = *(s32 *)((u32)D_001660C0 | 0x20000000u);
    func_00126BC0(D_00166068);
    return result;
}
